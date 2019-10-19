#include <vector>
#include <memory> //share_ptr,unique_ptr
#include <string>

//Strblob类通过share_ptr实现类对象共享底层数据
//委托vector完成部分操作
class StrBlob
{
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob();
    //使用可变形参列表
    //未使用explicit的initializer_list,可以在需要StrBlob对象时使用列表进行隐式类型转换，如作为函数的参数
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    //添加和删除元素
    void push_back(const std::string &s) const { data->push_back(s); }
    void pop_back();
    //元素访问
    std::string &front();
    const std::string &front() const;
    std::string &back();
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    //若data[i]不合法，就抛出一个异常
    void check(size_type i, const std::string &msg) const;
};
