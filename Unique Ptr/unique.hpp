template <typename T>
class unique{
    private:
        T* res;
    public:
        unique(T* a = nullptr) :res(a){};
        unique(const unique<T>& ptr) = delete;
        unique& operator= (const unique<T>& ptr) = delete;
        unique(unique<T>&& ptr){
            res = ptr.res;
            ptr.res = nullptr;
        }
        unique& operator= (unique<T>&& ptr){
            if(this != &ptr){
                if(res){
                    delete res;
                }
                
                res = ptr.res;
                ptr.res = nullptr;
            }

            return *this;
        }
        T* operator->(){
            return res;
        }
        T& operator*(){
            return *res;
        }
        ~unique(){
            if(res){
                delete res;
                res = nullptr;
            }
        }

        T* release(){
            T* temp = res;
            res = nullptr;
            return temp;
        };

        void reset(T* newPtr = nullptr){
            if (res != newPtr) {
                delete res;
                res = newPtr;
            }
        }

        void swap(unique& other){
            std::swap(res, other.res);
        }
};
