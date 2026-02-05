#include <algorithm>


namespace test{

    template<typename T>
    class unique_ptr{

    private:
        T* data = nullptr;

    public:
        explicit unique_ptr(T* pointer){
            if ( pointer != nullptr ) {
                data = pointer;
            }
            //if pointer is null that means new/malloc failed
        }

        ~unique_ptr() {
            delete data;    
        }

        unique_ptr(const unique_ptr& rhs) = delete;
        unique_ptr& operator=(const unique_ptr& rhs) = delete;

        unique_ptr(unique_ptr&& rhs) {
            data = rhs.data;
            rhs.data = nullptr;
        }
        unique_ptr& operator=(unique_ptr&& rhs) {
            if ( this != &rhs ) {
                this->data = rhs.data;
                rhs.data = nullptr;
            }
            return *this;
        }


        /*
        returns a ptr to the underlying, ownership is now responsibility of the caller
        */
        T* release() {
            if ( data == nullptr ) {
                return nullptr;
            }

            T* new_owner = data;
            data = nullptr;
            return new_owner;

        }

        /*
        reset() destroys what the unique_ptr currently owns and then replaces it (or makes it empty).
        */
        void reset(T* new_object) {
            if ( data != nullptr ) {
                delete data; data = nullptr;
            }

            data = new_object;
        }

        /*
        swap() swaps the unique ptr (swaps what they own)
        do not want to pass by copy since that is illegal and will trigger a move which will hollow out in the calling scope
        */
        void swap(unique_ptr<T>& rhs) {
            std::swap(data, rhs.data);
        }

        /*
        return a pointer to the managed object
        */
        T* get() {
            return data;
        }

        explicit operator bool() const {
            return (data ? true : false);
        }


    };

    template<typename T, typename... Args>
    unique_ptr<T> make_unique(Args&&... args){
        return unique_ptr<T>(new T(std::forward<Args>(args)...));
    }



}