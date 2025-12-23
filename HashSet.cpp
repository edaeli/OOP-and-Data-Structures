#include <vector>
#include <list>
#include <functional>

template <typename T, typename Hash = std::hash<T>>
class HashSet {
private:
    using Element = T;
    using Bucket = std::list<Element>;

    std::vector<Bucket> table;
    Hash hasher;
    size_t num_buckets;

    size_t getBucketIndex(const T& element) const {
        return hasher(element) % num_buckets;
    }

public:
    explicit HashSet(size_t initial_buckets = 101)
        : table(initial_buckets),
          num_buckets(initial_buckets)
    {
    }

    bool contains(const T& element) const {
        size_t index = getBucketIndex(element);
        const Bucket& bucket = table[index];

        for (const auto& x : bucket) {
            if (x == element)
                return true;
        }
        return false;
    }

    void insert(const T& element) {
        if (contains(element))
            return;

        size_t index = getBucketIndex(element);
        table[index].push_back(element);
    }

    void remove(const T& element) {
        size_t index = getBucketIndex(element);
        Bucket& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == element) {
                bucket.erase(it);
                return;
            }
        }
    }
};
