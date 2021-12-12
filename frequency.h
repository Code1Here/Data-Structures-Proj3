//  Created: Nov 21, 2021
//  Last Updated: Nov 21, 2021
//  Author: S. Miller

#ifndef FREQPROJECT_FREQUENCY_H
#define FREQPROJECT_FREQUENCY_H

#include <iostream>

/*
The Frequency class makes it easier to create a tree of data counts.

//Default Constructor
//None!

//VALUE CONSTRUCTORS

//Create a frequency object containing the data of s
//Any sort on this data will be on_frequency when true, on data otherwise
//Frequency is INITIALIZED TO ZERO, you most likely will ALWAYS want to call increment after creating an object
frequency(value_type  s, bool on_frequency=false);
//Same as above, except that sort_on_frequency is set to true
frequency(value_type s, size_t frequency);

//Comparison Operators
//For more readability, ONLY the <, <=, and == are included, you can trivially get around this limitation
//The field that gets compared is based on the objects sort_on_freq
//If sort_on_freq is true, comparison is based on the frequency_count
//If sort_on_freq is false, comparison is based on the data
bool operator<(frequency b) const;
bool operator<=(frequency b) const;
bool operator==(frequency b) const;

//Return the data, the data is NOT mutable (it could mess up a BST if it was.
const value_type& getData() const { return data; };

//Get the current frequency count of the object
size_t getFrequency() const { return frequency_count; };

//Increment the frequency of the object
void increment() { ++frequency_count; }

*/

namespace DS {
    template<typename T>
    class frequency {
    public:
        typedef T value_type;

        frequency() = delete;

        explicit frequency(value_type s, bool on_frequency = false) : sort_on_freq(on_frequency), data(std::move(s)),
                                                                      frequency_count(0) {}

        frequency(value_type s, size_t frequency) : sort_on_freq(true), data(std::move(s)),
                                                    frequency_count(frequency) {}

        bool operator<(frequency b) const { return sort_on_freq ? frequency_count < b.frequency_count : data < b.data; }

        bool operator<=(frequency b) const {
            return sort_on_freq ? frequency_count <= b.frequency_count : data <= b.data;
        }

        bool operator==(frequency b) const {
            return sort_on_freq ? frequency_count == b.frequency_count : data == b.data;
        }

        const value_type &getData() const { return data; };

        size_t getFrequency() const { return frequency_count; };

        void increment() { ++frequency_count; }

    private:
        bool sort_on_freq; //0=string, 1=frequency_count
        value_type data;
        size_t frequency_count;
    };

//Output the data and the frequency of the object separated by a comma
    template<typename T>
    std::ostream &operator<<(std::ostream &out, const frequency<T> &w) {
        out << "(" << w.getData() << "," << w.getFrequency() << ")";
        return out;
    }

}

#endif //FREQPROJECT_FREQUENCY_H