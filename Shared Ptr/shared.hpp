template<typename T>
class shared{
    private:
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
    shared(T* ptr = nullptr) : res(ptr), counter(new int(1)){};
    shared<T>(const shared<T>& ptr){
        res = ptr.res;
        counter = ptr.counter;
        incrementCounter();
    };

    shared<T>(shared<T>&& ptr){
        res = ptr.res;
        counter = ptr.counter;
        ptr.res = nullptr;
        ptr.counter = nullptr;
    };

    shared<T>& operator=(const shared<T>& ptr){
        if(this != &ptr){
            decrementCounter();
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
        counter = ptr  ? new int(1) : nullptr;
    }

    int getCount() const {
        return (counter ?  *counter : 0);
    }

    T* operator->() const {
        return res;
    }

    T& operator*() const {
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