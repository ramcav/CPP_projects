#include <vector>

namespace homework {

    /**
     * @brief A class that can hold elements of any type
     */
    template <typename T = int>
    class FlexibleContainer {

        
        std::vector<T> elements;

        public:

            /**
             * @brief Construct a new Flexible Container object
             * @param args The elements to initialize the container with
             * @tparam Args The types of the elements to initialize the container with
             * @details Initializes the container with the given elements using
             * a variadic template
             */
            template <typename... Args>
            FlexibleContainer(Args... args): elements{args...} {} // I made it so you can initialize the container with as many elements as you want

            /**
             * @brief Add an element to the container
             * @param element The element to add
             */
            void add(T element) {
                elements.push_back(element);
            }

            /**
             * @brief Get an element from the container
             * @param i The index of the element to get
             * @return The element at the given index
             * @throws std::out_of_range if the index is out of range
             */
            T get(int i) const {
                if (i >= this->elements.size()) {
                    throw std::out_of_range("Index out of range");
                }
                return this->elements[i];
            }

            /**
             * @brief Get the number of elements in the container
             * @return The number of elements in the container
             */

            int size() const {
                return this->elements.size();
            }

            /**
             * @brief Map a function over the elements of the container
             * @tparam Function The type of the function to map
             * @param function The function to map
             * @return void
             */
            template <typename Function>
            void map(Function function) {
                FlexibleContainer<T> cont;
                for (auto& n: this->elements) {
                    n = function(n);;
                }
                return;
            }
        
    };
}