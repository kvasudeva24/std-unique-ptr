


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

        unique_ptr(unique_ptr&& rhs) {/*TODO*/}
        unique_ptr& operator=(unique_ptr&& rhs) {/*TODO*/}


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
        /*TODO*/   
        }

        



    };

    template<typename T, typename... Args>
    unique_ptr<T> make_unique(Args&& ...){
        return unique_ptr<T>(new T(std::forward<Args>(args)...));
    }









}