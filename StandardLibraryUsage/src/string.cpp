#include <iostream>
#include <string>

int main(){
    /*string type object initialization*/
    //non-arguments
    std::string str;
    //construct with equal sign
    std::string str1 = "hello world!";
    //construct with char*
    std::string str2("hello world2!");
    const char* p = {"hello world3!"};
    std::string str3(p);
    //construct using repeation character
    std::string str4(5, 'A');
    //construct with copy constructor
    std::string str5(str2);
    //construct with move constructor
    std::string str6(move(str2));
    //construct using a range of designated characters
    std::string str7(str3, 4);//4 represents the start point
    std::string str8(str3, 4, 3);//3 represents the number of the designated characters 
    //string concatenation
    std::string str9 = str4 + "hxq";

    #ifdef __STRCTR__
    std::cout << "differnet constructors of string class comparision\n";
    std::cout << "non-arguments constructor:\nstd::string str\n" << "str: " << str << std::endl;
    std::cout << "construct with equal sign:\nstd::string str1 = \"hello world!\"\n" << "str1: " << str1 << std::endl;
    std::cout << "construct with char*:\nstd::string str2(\"hello world2!\")\n" << "str2: " << str2 << std::endl;
    std::cout << "construct using repeation character:\nstd::string str4(5, 'A')\n" << "str4: " << str4 << std::endl;
    std::cout << "construct with copy constructor:\nstd::string str5(str2)\n" << "str5: " << str5 << std::endl;
    std::cout << "construct with move constructor:\nstd::string str6(move(str2))\n" << "str6: " << str6 << std::endl;
    std::cout << "construct using a range of designated characters:\nstd::string str8(str3, 4, 3)\n" << "str8: " << str8 << std::endl;
    std::cout << "string concatenation:\nstd::string str9 = str4 + \"hxq\"\n" << "str9: " << str9 << std::endl;
    #endif

    #ifdef __STRACE__
    /*string element access*/
    std::cout << "string element access methods comparision\n";
    std::cout << "original string str3:" << str3 << std::endl;
    //at, contains subscript out of bound check
    std::cout << "access data using data (subscript out of bound check):\nstr3.at(1): " << str3.at(1) << std::endl;
    //[], doesn't contain subscript out of bounnd check
    std::cout << "access data using data []:\nstr3[1]: " << str3[1] << "\nstr[20]: " << str3[20] << std::endl;
    //front and back
    std::cout << "access data at front and at back:\nstr3.front(): " << str3.front() << "\nstr3.back(): " << str3.back() << std::endl;
    //get char* or cstring
    std::cout << "access cstring:\nstr3.data(): " << str3.data() << "\nstr3.c_str(): " << str3.c_str() << std::endl;
    #endif

    #ifdef __STRCAP__
    /*string capacity related operators*/
    std::cout << "string capacity related operators\n";
    std::cout << "original string str3: " << str3 << std::endl;
    std::cout << "is str3 is empty?\n" << "str3.empty(): " << std::boolalpha << str3.empty() << std::endl;
    std::cout << "get str size and capacity:\nstr3.size(): " << str3.size() << "  str3.capacity(): " << str3.capacity() << std::endl;
    str3.resize(20);
    std::cout << "str3.resize(20); //resize str3 to 20 bytes, and doenn't fill null sapce\n";
    std::cout << "string str3: " << str3 << std::endl;
    std::cout << "str3.size(): " << str3.size() << "  str3.capacity(): " << str3.capacity() << std::endl;
    str3.resize(13);
    str3.resize(20, 'A');
    std::cout << "str3.resize(20, 'A'); //resize str3 to 20 bytes, and filling null sapce with 'A'\n";
    std::cout << "string str3: " << str3 << std::endl;
    std::cout << "str3.size(): " << str3.size() << "  str3.capacity(): " << str3.capacity() << std::endl;
    str3.reserve(40);
    std::cout << "str3.reserve(40); //reserve 40 bytes to str3\n";
    std::cout << "string str3: " << str3 << std::endl;
    std::cout << "str3.size(): " << str3.size() << "  str3.capacity(): " << str3.capacity() << std::endl;
    str3.shrink_to_fit();
    std::cout << "str3.shrink_to_fit(); //strink str3 to fit the size\n";
    std::cout << "string str3: " << str3 << std::endl;
    std::cout << "str3.size(): " << str3.size() << "  str3.capacity(): " << str3.capacity() << std::endl;
    #endif

    #ifdef __STRITR__
    std::string strIt("hello world!");
    std::cout << "original string strIt: " << strIt << std::endl;
    std::cout << "iterator array using range operator:\n";
    for(auto& c : strIt){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::cout << "iterator string using iterator (const_iterator bans altering) operator:\n";
    std::string::iterator it = strIt.begin();
    for(; it != strIt.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "iterator string reversely using reverse_iterator (const_reverse_iterator bans altering) operator:\n";
    std::string::reverse_iterator rIt = strIt.rbegin();
    for(; rIt != strIt.rend(); rIt++){
        std::cout << *rIt << " ";
    }
    std::cout << std::endl;
    #endif

    #ifdef __STRCMP__
    /*string compare*/
    std::string strCmp1 = "hello world!";
    std::string strCmp2 = "hellO world!";
    std::cout << "string compare operations comparision\n";
    std::cout << "original string: \n";
    std::cout << "string1:" << strCmp1 << "\tstring2:" << strCmp2 << std::endl;
    std::cout << "Is string1 same as string2? \t\t" << std::boolalpha << (strCmp1 == strCmp2) << std::endl;
    std::cout << "Is string1 greater than string2?\t" << std::boolalpha << static_cast<bool>(strCmp1.compare(strCmp2)) << std::endl;
    std::cout << "Does string1 start with \"hel\"?\t\t" << std::boolalpha << strCmp1.starts_with("hel") << std::endl;
    std::cout << "Does string1 end with \"!!\"?\t\t" << std::boolalpha << strCmp1.ends_with("!!") << std::endl;
    #endif

    #ifdef __STRINS__
    /*string insertion*/
    std::string strIns1 = "hello world!";
    std::string strIns2 = "*****";
    std::cout << "string insertion operations comparision\n";
    std::cout << "original string: \n";
    std::cout << "string1:" << strIns1 << "\tstring2:" << strIns2 << std::endl;
    strIns1.push_back('*');
    std::cout << "append one character \"*\" at the end of string1" << strIns1 << std::endl;
    strIns1.pop_back();
    std::cout << "erase one charaster \"*\" at the end of string1" << strIns1 << std::endl;
    strIns1.insert(2, strIns2, 2 , 2);
    std::cout << "insert the substring (from pos 2 to 4) of string2 into string1 at the position 2: " << strIns1 << std::endl;
    strIns1.append(strIns2, 2, 2);
    std::cout << "append the substring (from pos 2 to 4) of string2 into string1 at the end: " << strIns1 << std::endl;
    strIns1.erase(2, 2);
    strIns1.erase(strIns1.end()-2, strIns1.end());
    std::cout << "erase characters appended and inserted of string1: " << strIns1 << std::endl;
    strIns1.clear();
    std::cout << "clear string1: " << strIns1 << std::endl;
    #endif

    #ifdef __STRREP__
    /*string replace and fetch substring*/
    std::string strRep1("hello world!");
    std::string strRep2("*****");
    std::cout << "string replace operations comparision\n";
    std::cout << "original string: \n";
    std::cout << "string1:" << strRep1 << "\tstring2:" << strRep2 << std::endl;
    strRep1.replace(2, 4, strRep2, 1, 4);
    std::cout << "replace 4 characters from pos 2 of string1 with substring (from 1 to 5) of string2: " << strRep1 << std::endl;
    std::string subStr = strRep1.substr(2, 4);
    std::cout << "fetch a substring contains 4 characters of string1 started at pos 2: " << subStr << std::endl;
    #endif
}