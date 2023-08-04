#include <iostream>
#include <vector>

class MyObject {
public:
  MyObject() {
  }
  
  MyObject(MyObject &&other) {
    
  }

  MyObject& operator=(MyObject&& other) {
    if (this != &other) {
      
    }

    return *this;
  }
};

class Buffer {
public:
  Buffer(int size = 0) {
    if (size > 0) {
      buffer_size = size;
      p_buffer = new char[buffer_size];
    }
  }

  ~Buffer() {
    if (buffer_size > 0 && p_buffer != nullptr) {
      delete[] p_buffer;
    }
  }

  Buffer(Buffer &&other) {
    p_buffer = other.p_buffer;
    buffer_size = other.buffer_size;
  }

  Buffer& operator=(Buffer&& other) {
    if (this != &other) {
      delete[] p_buffer;

      p_buffer = other.p_buffer;
      buffer_size = other.buffer_size;
    }
    return *this;
  }

  void shuffle_buffer() {
    for(int i = 0; i < buffer_size; i++) {
      
    }
  }
private:
  char *p_buffer{nullptr};
  int buffer_size{0};
};

int main() {
  Buffer buffer(10);
  /*
  std::vector<MyObject> vec;
  MyObject temp;
  vec.push_back(std::move(temp));
  */
  return 0;
}
