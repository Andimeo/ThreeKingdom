#include <set>

using namespace std;

template<typename T>
class CommonSet {
public:
	CommonSet(){}
	~CommonSet(){}

	int size() const{
		return this->container.size();
	}

	bool contains(const T& ele){
		return this->container.find(ele) != this->container.end();
	}
	int add(const T& ele) {
		this->container.insert(ele);
		return this->container.size();
	}
	int remove(const T& ele){
		auto iter = this->container.find(ele);
		if(iter != this->container.end())
		this->container.erase(iter);
		return this->container.size();
	}

	typename set<T>::iterator begin() const {
		return this->container.begin();
	}
	typename set<T>::iterator end() const {
		return this->container.end();
	}

private:
	set<T> container;
};