#ifndef KTB_TOOLS_SIGNAL_HPP_INCLUDED
#define KTB_TOOLS_SIGNAL_HPP_INCLUDED
namespace Ktb{

namespace Tools{
template <typename ... Args>
class Signal;
namespace Details{
	class SignalBase;
    class ConnectionBase{
	public:
	    ConnectionBase() = default;
		ConnectionBase(ConnectionBase const &) =delete;
		ConnectionBase & operator= (ConnectionBase const &)= delete;
		virtual ~ConnectionBase() = default;
		void block()const {
			blocked_=true;
		}
		void unBlock() const{
			blocked_=false;
		}
		bool blocked() const{
			return connected() || blocked_;
		}
		bool connected() const{
			return sig_!=nullptr;
		}
		virtual bool disconnect() const = 0;
		virtual void signalDeath() const = 0;
		virtual ConnectionBase* clone() const = 0;
		virtual void updateDb() const = 0;
	private:
		mutable bool blocked_{false};
	};
	template <typename ... Args>
	class ConnectionImpl : public ConnectionBase{
	using sig_t = ::Signals::Signals<Args ...>;
	public:
		ConnectionImpl(size_t id, sig_t * sig):id_{id},sig_{sig}{}
		~ConnectionImpl(){
			disconnect();
		}
		void disconnect() const final override{
			if(sig_){
				sig_->disconnect(id_);
				sig_=nullptr;
			}
		}
		void signalDeath() const final override{
			sig_=nullptr;
		}
		ConnectionBase * clone() const final override{
			return new ConnectionImpl{id_, sig_};
		}
		void updateDb() const{
			if(sig_)
				sig_->update(id_, this);
		}
	private:
		size_t id_;
	    sig_t sig_;
	};
}
class Connection{
public:
	Connection(Details::ConnectionBase * pimpl = nullptr):pimpl_{pimple}{}
	Connection(Connection const & other):pimpl_{other.clone()}{}
	Connection & operator=(Connection const & other){
		Connection temp(other).swap(*this);
		return *this;
	}
	~Connection(){
		delete pimpl_;
	}
	void swap(Connection & other){
			std::swap(pimpl_, other.pimpl_);
			if(pimpl_)
				pimpl_->updateDb();
	}
	void block() const{
		if(pimpl_)
			pimpl_.block();
	}
	void unBlock() const{
		if(pimpl_)
			pimpl_.unBlock();
	}
	bool blocked_() const{
		return pimpl_ && pimpl_.blocked();
	}
	void disconnect() const{
		if(pimpl_)
			pimpl_->disconnect();
	}
	bool connected() const{
		return pimpl_ && pimpl_->connected();
	}
private:
	mutable Details::ConnectionBase * pimpl_;
};
template <typename ... Args>
class Signal{
public:
    using slot_t = std::function<void (Args ...)>;
	struct ConnInfo{
		Details::ConnectionImpl * connection;
		slot_t slot;
	};
	~Signal(){
		for(auto & it : allConns_){
			it.second->signalDeath();
		}
	}
	Connection connect(slot_t const & s) const{
		auto ptr= std::make_unique<Details::ConnectionImpl>(nextId_, this);
		allConns_[nextId_]= ConnInfo{ptr.get(),s);
		++nextId_;
		return Connection(ptr.release());
	}
	void disconnect(size_t id) const{
		allConns_.erase(id);
	}
	void update(size_t id, Details::ConnectionBase* conn) const{
		allConns_[id].connection= conn;
	}
	void block() const{
		blocked_=true;
	}
	void unBlock() const{
		blocked_=false();
	}
	bool blocked() const{
		return blocked_;
	}
	void emit(Args ... args){
		if(!blocked()){
			for(auto & it: allConns){
				if(!it.connection->blocked()){
					std::forward(it.slot(args)) ...;
				}
			}
		}
	}
private:
    mutable size_t nextId_{1};
	mutable bool blocked_{false};
	mutable std::hashmap<size_t, ConnInfo> allConns_;
};
} // namespace Tools
} // namespace Ktb
# endif // KTB_TOOLS_SIGNAL_HPP_INCLUDED
