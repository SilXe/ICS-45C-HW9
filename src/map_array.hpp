#ifndef MAP_ARRAY_HPP
#define MAP_ARRAY_HPP

#include <algorithm>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>

template <typename Key, typename Value>
class MapArray {
public:
    class ArrayIterator {
    public:
        // Iterator traits:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::pair<Key, Value>;
        using difference_type = std::ptrdiff_t;
        using pointer = std::pair<Key, Value>*;
        using reference = std::pair<Key, Value>&;

        explicit ArrayIterator(std::pair<Key, Value>* ptr = nullptr) : ptr(ptr) {}

        ArrayIterator& operator++() {
            ++ptr;
            return *this;
        }

        ArrayIterator operator++(int) {
            ArrayIterator temp = *this;
            ++(*this);
            return temp;
        }

        ArrayIterator& operator--() {
            --ptr;
            return *this;
        }

        ArrayIterator operator--(int) {
            ArrayIterator temp = *this;
            --(*this);
            return temp;
        }

        ArrayIterator& operator+=(difference_type d) {
            ptr += d;
            return *this;
        }

        ArrayIterator& operator-=(difference_type d) {
            ptr -= d;
            return *this;
        }

        friend ArrayIterator operator+(ArrayIterator it, difference_type d) {
            return ArrayIterator(it.ptr + d);
        }

        friend ArrayIterator operator+(difference_type d, ArrayIterator it) {
            return ArrayIterator(it.ptr + d);
        }

        friend ArrayIterator operator-(ArrayIterator it, difference_type d) {
            return ArrayIterator(it.ptr - d);
        }

        friend difference_type operator-(ArrayIterator lhs, ArrayIterator rhs) {
            return lhs.ptr - rhs.ptr;
        }

        std::pair<Key, Value>& operator*() const {
            return *ptr;
        }

        std::pair<Key, Value>* operator->() const {
            return ptr;
        }

        std::pair<Key, Value>& operator[](difference_type d) const {
            return *(ptr + d);
        }

        bool operator==(const ArrayIterator& other) const = default;

        bool operator!=(const ArrayIterator& other) const {
            return !(*this == other);
        }

    private:
        std::pair<Key, Value>* ptr;
    };

    using value_type = std::pair<Key, Value>;
    using iterator = ArrayIterator;
    // Normally there would also be a const_iterator

    ArrayIterator begin() { return ArrayIterator(data.data()); }

    ArrayIterator end() { return ArrayIterator(data.data() + data.size()); }

    Value& operator[](const Key& key) {
        auto it = std::ranges::lower_bound(data, key, {}, &std::pair<Key, Value>::first);
        
        if (it == data.end() || it->first != key) {
            it = data.insert(it, {key, Value{}});
        }

        return it->second;
    }

private:
    std::vector<std::pair<Key, Value>> data;
};

#endif
