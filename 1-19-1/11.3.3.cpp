/*
From:ITC
11
STL defects
11.3
"use auto pointer
"
11.3.3
" function parameters should not be of type ""std::unique_ptr<T> const &"""
*/

using namespace std;                                                                                                               
class Shape {
private:
    int a;
    char* b;
};
void draw(unique_ptr<Shape> const& shape) {
}                                          // /*Tool should detect this line as error*/ /*ERROR:STL error*/
void use_auto_pointer_003()
{
    vector<unique_ptr<Shape>> v;
    for (auto& shape : v) {
        if (shape) {
            draw(shape);
        }
    }
}
