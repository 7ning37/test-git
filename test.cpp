/*设计并实现一个面向对象程序——图书信息管理系统，数据保存在磁盘文件中，
基本功能如下：
（1）新增图书
向系统中添加新书，新书信息包括书号、书名、首作、出版社、出版年和价格等。
（2）删除图书
按照书号删除指定图书。
（3）修改图书
按照书号修改指定图书。
（4）查找图书
按照书名查看指定图书信息。
（5）显示图书
显示系统中的所有图书信息。
（6）清空图书
清空系统中所有图书。
（0）退出系统
退出图书管理系统。*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cstdlib> //用于实现清屏

// 防止utf-8乱码
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;
const string DATA_FILE = "test.txt";
void displaymenu();
void loadbooksFromFile();
void saveallbooksToFile();
void addbook();
void deletebook();
void modifybook();
void searchbook();
void displayallbooks();
void clearallbooks();
void initDataFile();

// 图书信息类
class Book
{
private:
    string book_number;    // 书号
    string book_name;      // 书名
    string book_author;    // 作者
    string book_publisher; // 出版社
    int book_year;         // 出版年
    double book_price;     // 价格

public:
    // 构造函数
    Book() : book_number(""), book_name(""), book_author(""),
             book_publisher(""), book_year(0), book_price(0.0) {};

    Book(string number, string name, string author, string publisher, int year, double price) : book_number(number), book_name(name), book_author(author), book_publisher(publisher),
                                                                                                book_year(year), book_price(price) {};

    // 设置函数值
    void setbook_number(string number)
    {
        book_number = number;
    }
    void setbook_name(string name)
    {
        book_name = name;
    }
    void setbook_author(string author)
    {
        book_author = author;
    }
    void setbook_publisher(string publisher)
    {
        book_publisher = publisher;
    }
    void setbook_year(int year)
    {
        book_year = year;
    }
    void setbook_price(double price)
    {
        book_price = price;
    }

    // 获取函数值
    string getbook_number() const
    {
        return book_number;
    }
    string getbook_name() const
    {
        return book_name;
    }
    string getbook_author() const
    {
        return book_author;
    }
    string getbook_publisher() const
    {
        return book_publisher;
    }
    int getbook_year() const
    {
        return book_year;
    }
    double getbook_price() const
    {
        return book_price;
    }

    // 显示图书信息
    void displayBookinformation() const
    {
        cout << "\n图书信息:" << endl;
        cout << "书号: " << book_number << endl;
        cout << "书名: " << book_name << endl;
        cout << "作者: " << book_author << endl;
        cout << "出版社: " << book_publisher << endl;
        cout << "出版年: " << book_year << "年" << endl;
        cout << "价格: " << fixed << setprecision(2) << book_price << "元" << endl;
    }

    // 保存图书信息到文件
    void saveToFile(ofstream &outfile) const
    {
        outfile << book_number << "\t\t" << book_name << "\t\t" << book_author << "\t\t"
                << book_publisher << "\t\t" << book_year << "\t\t" << book_price << endl;
    }
};
// 使每次结束后txt文档保存下来
vector<Book> books;

// 添加txt文本标题
void initDataFile()
{
    ifstream infile(DATA_FILE);
    if (!infile)
    {
        // 文件不存在，创建并写入标题行
        ofstream outfile(DATA_FILE);
        if (outfile)
        {
            outfile << "书号\t\t书名\t\t作者\t\t出版社\t\t出版年\t\t价格" << endl;
            outfile.close();
            cout << "已创建数据文件并添加标题行。" << endl;
        }
    }
}

// 目录
void displaymenu()
{
    cout << "\n~~~~~~~~~~ 图书信息管理系统 ~~~~~~~~~~" << endl;
    cout << "\t" << "1. 新增图书" << endl;
    cout << "\t" << "2. 删除图书" << endl;
    cout << "\t" << "3. 修改图书" << endl;
    cout << "\t" << "4. 查找图书" << endl;
    cout << "\t" << "5. 显示图书" << endl;
    cout << "\t" << "6. 清空图书" << endl;
    cout << "\t" << "0. 退出系统" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "请选择操作 (0—6): ";
}

// 从文件加载图书
void loadbooksFromFile()
{
    ifstream infile(DATA_FILE);
    if (!infile)
    {
        cout << "数据文件不存在，将创建新文件。" << endl;
        return;
    }
    // 读取并跳过第一行（标题行）
    string header;
    getline(infile, header);
    books.clear();
    string number, name, author, publisher;
    int year;
    double price;
    while (infile >> number >> name >> author >> publisher >> year >> price)
    {
        Book book(number, name, author, publisher, year, price);
        books.push_back(book);
    }
    infile.close();
}

// 保存所有图书到文件
void saveallbooksToFile()
{
    ofstream outfile(DATA_FILE);
    if (!outfile)
    {
        cout << "无法打开文件进行保存！" << endl;
        return;
    }
    // 添加标题行
    // 设置左对齐和固定宽度（每个字段20个字符宽度）
    outfile << "书号\t\t书名\t\t作者\t\t出版社\t\t出版年\t\t价格（元）" << endl;
    for (const auto &book : books)
    {
        outfile << book.getbook_number() << "\t\t"
                << book.getbook_name() << "\t\t"
                << book.getbook_author() << "\t\t"
                << book.getbook_publisher() << "\t\t"
                << book.getbook_year() << "\t\t"
                << fixed << setprecision(2) << book.getbook_price() << endl;
    }
    outfile.close();
}

// 新增图书
void addbook()
{
    cout << "\n=== 新增图书功能 ===" << endl;
    string number, name, author, publisher;
    int year;
    double price;
    cout << "请您输入图书以下信息" << endl;
    cout << "一、书号：";
    cin >> number;
    cout << "二、书名：";
    cin >> name;
    cout << "三、作者：";
    cin >> author;
    cout << "四、出版社：";
    cin >> publisher;
    cout << "五、出版年：";
    cin >> year;
    cout << "六、价格（元）：";
    cin >> price;
    // 检查书号是否已存在
    bool exists = false;
    for (const auto &book : books)
    {
        if (book.getbook_number() == number)
        {
            exists = true;
            break;
        }
    }
    if (exists)
    {
        cout << "错误：书号 " << number << " 已存在！" << endl;
    }
    else
    {
        Book newbook(number, name, author, publisher, year, price);
        books.push_back(newbook);

        // 追加到文件（不是重写整个文件）
        ofstream outfile(DATA_FILE, ios::app);
        if (outfile)
        {
            outfile << number << "\t\t" << name << "\t\t" << author << "\t\t"
                    << publisher << "\t\t" << year << "\t\t"
                    << fixed << setprecision(2) << price << endl;
            outfile.close();
        }
        cout << "图书信息已成功录入并保存到 " << DATA_FILE << endl;
    }
}

// 删除图书
void deletebook()
{
    cout << "\n=== 删除图书功能 ===";
    if (books.size() == 0)
    {
        cout << "当前没有图书信息！" << endl;
        return;
    }
    string booknumber;
    cout << "请输入要删除的图书书号：";
    cin >> booknumber;
    bool found = false;
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if (it->getbook_number() == booknumber)
        {
            found = true;
            cout << "找到图书：" << it->getbook_name() << endl;
            cout << "确认删除吗？(确定/取消): ";
            string confirm;
            cin >> confirm;
            if (confirm == "确定")
            {
                books.erase(it);
                saveallbooksToFile();
                cout << "图书删除成功！" << endl;
            }
            else
            {
                cout << "取消删除操作。" << endl;
            }
            break;
        }
    }

    if (!found)
    {
        cout << "未找到书号为 " << booknumber << " 的图书！" << endl;
    }
}

// 修改图书
void modifybook()
{
    cout << "\n=== 修改图书功能 ===" << endl;

    if (books.size() == 0)
    {
        cout << "当前没有图书信息！" << endl;
        return;
    }

    string booknumber;
    cout << "请输入要修改的图书书号：";
    cin >> booknumber;

    bool found = false;
    for (auto &book : books)
    {
        if (book.getbook_number() == booknumber)
        {
            found = true;
            cout << "\n当前图书信息：" << endl;
            book.displayBookinformation();
            cout << "\n请输入新的信息（直接回车跳过修改）：" << endl;
            string newname, newauthor, newpublisher;
            int newyear;
            double newprice;
            cin.ignore();
            cout << "新书名（输入回车跳过修改）：";
            getline(cin, newname);
            if (!newname.size() == 0)
            {
                book.setbook_name(newname);
            }
            cout << "新作者（输入回车跳过修改）：";
            getline(cin, newauthor);
            if (!newauthor.size() == 0)
            {
                book.setbook_author(newauthor);
            }
            cout << "新出版社（输入回车跳过修改）：";
            getline(cin, newpublisher);
            if (!newpublisher.size() == 0)
            {
                book.setbook_publisher(newpublisher);
            }
            cout << "新出版年（输入0跳过）：";
            string yearInput;
            getline(cin, yearInput);
            if (!yearInput.size() == 0)
            {
                try
                {
                    newyear = stoi(yearInput);
                    if (newyear != 0)
                    {
                        book.setbook_year(newyear);
                    }
                }
                catch (...)
                {
                    cout << "年份输入无效，跳过修改。" << endl;
                }
            }
            cout << "新价格（输入0跳过）：";
            string priceInput;
            getline(cin, priceInput);
            if (!priceInput.size() == 0)
            {
                try
                {
                    newprice = stod(priceInput);
                    if (newprice != 0)
                    {
                        book.setbook_price(newprice);
                    }
                }
                catch (...)
                {
                    cout << "价格输入无效，跳过修改。" << endl;
                }
            }
            saveallbooksToFile();
            cout << "图书信息修改成功！" << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "未找到书号为 " << booknumber << " 的图书！" << endl;
    }
}

// 查找图书
void searchbook()
{
    cout << "\n=== 查找图书功能 ===" << endl;
    if (books.size() == 0)
    {
        cout << "没有该图书信息！" << endl;
        return;
    }
    int searchchoice;
    cout << "请选择查找方式：" << endl;
    cout << "1. 按书名查找" << endl;
    cout << "2. 按书号查找" << endl;
    cout << "3. 按作者查找" << endl;
    cout << "4. 按出版社查找" << endl;
    cout << "0. 返回主菜单" << endl;
    cout << "请输入您的选择: ";
    cin >> searchchoice;
    if (searchchoice == 0)
    {
        return;
    }
    string keyword;
    bool found = false;

    cin.ignore(); // 清除输入缓冲区

    switch (searchchoice)
    {
    case 1:
        cout << "请您输入书名: ";
        getline(cin, keyword);
        for (const auto &book : books)
        {
            if (book.getbook_name().find(keyword) != string::npos)
            {
                book.displayBookinformation();
                found = true;
            }
        }
        break;
    case 2:
        cout << "请您输入书号: ";
        getline(cin, keyword);
        for (const auto &book : books)
        {
            if (book.getbook_number() == keyword)
            {
                book.displayBookinformation();
                found = true;
                break;
            }
        }
        break;
    case 3:
        cout << "请您输入作者: ";
        getline(cin, keyword);
        for (const auto &book : books)
        {
            if (book.getbook_author().find(keyword) != string::npos)
            {
                book.displayBookinformation();
                found = true;
            }
        }
        break;
    case 4:
        cout << "请您输入出版社: ";
        getline(cin, keyword);
        for (const auto &book : books)
        {
            if (book.getbook_publisher().find(keyword) != string::npos)
            {
                book.displayBookinformation();
                found = true;
            }
        }
        break;
    default:
        cout << "无该选项！" << endl;
        return;
    }
    if (!found)
    {
        cout << "未找到符合条件的图书！" << endl;
    }
}

// 显示所有图书
void displayallbooks()
{
    cout << "\n=== 显示图书功能 ===" << endl;
    if (books.size() == 0)
    {
        cout << "当前没有图书信息！" << endl;
        return;
    }
    cout << "当前共有 " << books.size() << " 本图书：" << endl;
    for (int i = 0; i < books.size(); i++)
    {
        cout << "\n=== 第 " << i + 1 << " 本图书 ===" << endl;
        books[i].displayBookinformation();
    }
}

// 清空图书
void clearallbooks()
{
    cout << "\n=== 清空图书功能 ===" << endl;
    if (books.size() == 0)
    {
        cout << "当前没有图书信息！" << endl;
        return;
    }
    cout << "请选择清空方式：" << endl;
    cout << "1. 清空所有图书信息" << endl;
    cout << "2. 清空指定图书信息" << endl;
    cout << "0. 返回主菜单" << endl;
    cout << "请选择您的清空方式: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        cout << "警告：您确定要删除所有图书信息吗？该过程不可撤销！(确定/取消): ";
        string confirm;
        cin >> confirm;
        if (confirm == "确定")
        {
            books.clear();
            saveallbooksToFile();
            cout << "已清除所有图书信息！" << endl;
        }
        else if (confirm == "取消")
        {
            cout << "\t操作已取消。" << endl;
        }
    }
    else if (choice == 2)
    {
        deletebook();
    }
}

int main()
{
    // 设置控制台编码为 UTF-8（Windows）
#ifdef _WIN32
    SetConsoleOutputCP(65001); // 设置输出编码为 UTF-8
    SetConsoleCP(65001);       // 设置输入编码为 UTF-8
#endif
    // 初始化数据文件
    initDataFile();

    // 程序启动时加载数据
    loadbooksFromFile();

    int Num;
    do
    {
        system("cls");
        cout << "\n        " << "欢迎登录图书馆管理系统" << endl;
        displaymenu();
        cin >> Num;
        switch (Num)
        {
        case 0:
            saveallbooksToFile();
            cout << "本次服务结束，欢迎您下次使用！" << endl;
            break;
        case 1:
            addbook();
            break;
        case 2:
            deletebook();
            break;
        case 3:
            modifybook();
            break;
        case 4:
            searchbook();
            break;
        case 5:
            displayallbooks();
            break;
        case 6:
            clearallbooks();
            break;
        default:
            cout << "无此功能，请输入0-6之间的数字！" << endl;
        }
        if (Num != 0)
        {
            cout << "\n按回车键继续...";
            cin.ignore();
            cin.get();
        }
    } while (Num != 0);
    return 0;
}