template <typename T>
class unique{ // capital naming pls
    private: // indent for access specifiers
        T* res;
    public:
        unique(T* a = nullptr) :res(a){};
        unique(const unique<T>& ptr) = delete;
        unique& operator= (const unique<T>& ptr) = delete;
        unique(unique<T>&& ptr){// lets mark the move as noexcept, please learn about it
            res = ptr.res;
            ptr.res = nullptr;
        }
        unique& operator= (unique<T>&& ptr){
            if(this != &ptr){ // you loose the ptr here, add test
                if(res){
                    delete res;
                }
                
                res = ptr.res;
                ptr.res = nullptr;
            }

            return *this;
        }
        T* operator->(){ // can be cont function
            return res;
        }
        T& operator*(){ // can be const function as it is don't change anything in function
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

// add explicit operator bool() const noexcept 
// add make_unique function
