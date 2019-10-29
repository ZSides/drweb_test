#include <bits/stdc++.h>
template<class TKey, class TValue>
class Dictionary
{
public:
	virtual ~Dictionary() = default;

	virtual const TValue& Get(const TKey& key) const = 0;
	virtual void Set(const TKey& key, const TValue& value) = 0;
	virtual bool IsSet(const TKey& key) const = 0;
};
template<class TKey>
class NotFoundException : public std::exception
{
public:
	virtual const TKey& GetKey() const noexcept = 0;
};
template<class TKey>
class NFExc : NotFoundException<TKey> 
{
public:
	virtual const TKey& GetKey() const noexcept
	{
		return k;
	}
	NFExc(const TKey& key) { k = key; }
private:
	TKey k;
};
template<class TKey, class TValue>
class Dict : public Dictionary<TKey, TValue> 
{
public:
	virtual const TValue& Get(const TKey& key) const
	{
		if (!IsSet(key))
			throw NFExc<TKey>(key);
		return map.at(key);
	}
	virtual void Set(const TKey& key, const TValue& value)
	{
		map[key] = value;
	}
	virtual bool IsSet(const TKey& key) const 
	{
		return map.find(key) != map.end();
	}
private:
	std::map<TKey, TValue> map;
};
int main() {
	Dict<std::string, int> d;
	d.Set("hello", 1);
	d.Set("hai", 11);
	d.Set("world", 21);
	d.Set("world", 12);
	try 
	{
		std::cout << d.Get("world") << '\n';
		std::cout << d.Get("NoNoNoNoNo") << '\n';
		std::cout << d.Get("hai") << '\n';
	}
	catch (NFExc<std::string> e) 
	{
		std::cout << "error, key " << e.GetKey() << " not found." << '\n';
	}
}
