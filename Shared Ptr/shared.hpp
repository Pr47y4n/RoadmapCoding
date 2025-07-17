template<typename T>
class shared{ // uppercase for class names pls
    private: // indent
    T* res;
    int* counter;

    void incrementCounter(){
        if(counter){
            (*counter)++;
        }
    }

    void decrementCounter(){
        if(counter){
            (*counter)--;
            if((*counter) == 0){
                    delete res;
                    delete counter;
                    res = nullptr;
                    counter = nullptr;
            }
        }
    }
    
    public:
    shared(T* ptr = nullptr) // keep easey to read
        : res(ptr)
        , counter(new int(1)) // what if nullptr?
    {}; // why semicolon?

    shared<T>(const shared<T>& ptr){
        res = ptr.res;
        counter = ptr.counter;
        incrementCounter();
    };

    shared<T>(shared<T>&& ptr){ // move assignment and this move share the same logic, could have used one fuinction.
        res = ptr.res;
        counter = ptr.counter;
        ptr.res = nullptr;
        ptr.counter = nullptr;
    };

    shared<T>& operator=(const shared<T>& ptr){
        if(this != &ptr){
            decrementCounter(); // what if the only one? wouldn't you loose it at this point?
            res = ptr.res;
            counter = ptr.counter;
            incrementCounter();
        }
        return *this;
    }

    shared<T>& operator=(shared<T>&& ptr){
        if(this != &ptr){
            decrementCounter();
            res = ptr.res;
            counter = ptr.counter;
            ptr.res = nullptr;
            ptr.counter = nullptr;
        }
        return *this;
    }

    void reset(T* ptr){
        decrementCounter();
        res = ptr;
        counter = ptr  ? new int(1) : nullptr; // good
    }

    int getCount() const {
        return (counter ?  *counter : 0);
    }

    T* operator->() const { // null?
        return res;
    }

    T& operator*() const { // null?
        return (*res);
    }

    operator bool() const {
        return res != nullptr;
    }

    T* get() const {
        return res;
    }

    bool unique() const{
        return counter && (*counter == 1);
    }

    ~shared(){
        decrementCounter();
    } 
};
// implement swap, can be used to decrease the code repitition
// test cases?
// for the start this is great, here is more upgraded version:

// instead of just an int* counter, real std::shared_ptr uses a control block that contains:
// 1) strong ref count (shared)
// 2) weak ref count (if weak_ptr exists)
// 3) deleter (optional) // not madatory for now can be skipped
// 4) possibly type-erased pointer to the managed object (void*)

// create function named make_sharedthat manages the creation of the shared ptr
// add use_count() and expired()
