#include <iostream>
#include <iomanip>
#include <map>
#include <limits>

template <typename K, typename V>
class interval_map
{
	friend void IntervalMapTest();
	V m_valBegin;

public:
	std::map<K, V> m_map;
	interval_map(V const &val) : m_valBegin(val)
	{
	}

	void assign(K const &keyBegin, K const &keyEnd, V const &val)
	{
		if (keyBegin >= keyEnd)
		{
			return;
		}

		if (m_map.size() == 0)
		{
			m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), m_valBegin));
		}

		typename std::map<K, V>::iterator lowKeyBegin = m_map.lower_bound(keyBegin);
		typename std::map<K, V>::iterator upKeyEnd = m_map.upper_bound(keyEnd);
		typename std::map<K, V>::iterator prevKeyEnd = std::prev(upKeyEnd);
		typename std::map<K, V>::iterator iteratorBegin;
		typename std::map<K, V>::iterator iteratorEnd;

		if (prevKeyEnd->second != val)
		{
			if ((prevKeyEnd->first >= keyEnd) && (keyEnd >= prevKeyEnd->first))
			{
				iteratorEnd = prevKeyEnd;
			}
			else
			{
				iteratorEnd = m_map.insert_or_assign(upKeyEnd, keyEnd, prevKeyEnd->second);
			}
		}
		else
		{
			iteratorEnd = upKeyEnd;
		}

		if (lowKeyBegin != m_map.begin())
		{
			auto prevIter = std::prev(lowKeyBegin);
			if (prevIter->second != val)
			{
				iteratorBegin = m_map.insert_or_assign(lowKeyBegin, keyBegin, val);
			}
			else
			{
				iteratorBegin = prevIter;
			}
		}
		else
		{
			iteratorBegin = m_map.insert_or_assign(lowKeyBegin, keyBegin, val);
		}

		auto nextIterOfBegin = std::next(iteratorBegin);
		if (nextIterOfBegin != m_map.end())
		{
			m_map.erase(nextIterOfBegin, iteratorEnd);
		}
	}

	V const &operator[](K const &key) const
	{
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin())
		{
			return m_valBegin;
		}
		else
		{
			return (--it)->second;
		}
	}
};