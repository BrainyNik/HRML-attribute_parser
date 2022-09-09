/* HRML listing

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value
 */
#include <iostream>
#include <string>
#include <sstream>
#include <map>
namespace attributeparser
{

    

   std::map<std::string, std::string> attribute_parser(int n, int q)
    {
        std::string curr = "", attr_name;
        std::map<std::string, std::string> m;

        for (int i = 0; i < n; i++)
        {
            std::string line, tag;
            std::getline(std::cin, line);

            std::stringstream ss(line);
           std::string extract;
            /* Processing the HRML lines extract is the variable holding the
            tokens extracetd from the ss until it encounters a space getline
            will stop at each space ans then extract the
            word that is present after the space */
            while (std::getline(ss, extract, ' '))
            {
                /*
                in this loop we will convert this line :
                 <tag1 value = "HelloWorld">
                 and map it into this :
                 m[tag1~value] = HelloWorld

                  */
                // if its an opening tag
                if (extract[0] == '<')
                {
                    // if its not an closing tag store it in tag variable
                    if (extract[1] != '/')
                    {
                        //  remove the opening bracket
                        tag = extract.substr(1);
                        // if the tag is does not have any attributes then remove the last bracket and store it
                        if (tag[tag.length() - 1] == '>')
                        {
                            // tag = tag.substr(0, tag.length() - 1); or
                            tag.pop_back();
                            /*

                                                        now the tag will have attributes like
                                                        tag1
                                                        tag2
                                                        tag3 etc */
                        }
                        /* check if any nesting of attrributes is needed*/
                        if (curr.size() > 0)
                        {
                            curr = curr + "." + tag;
                        }
                        else
                        {
                            curr = tag;
                        }
                    }

                    else
                    {
                        /* if its an closing tag </tag2>  :
                        first we will remove the </and then we find the closing tag and remove it as well and then remove the tag2 from the curr nesting if present or we will just delete the tag value from the curr value setting it to "" if there is no nesting
                        */
                        tag = extract.substr(2, extract.find('>')); // removing the </ and > from the tag

                        size_t pos = curr.find("." + tag);

                        if (pos != std::string::npos)
                        {
                            // remove the nested tag and update the curr
                            curr = curr.substr(0, pos);
                        }
                        else
                        {
                            // if there is no nesting in curr then just clear it
                            curr = "";
                        }
                    }
                }
                // if its an attrubite value rather than tag then map this value to its respective attribute name
                else if (extract[0] == '"')
                {
                    size_t pos = extract.find_last_of('"');

                    std::string atttr_value = extract.substr(1, pos - 1);

                    // add  to map
                    m[attr_name] = atttr_value;
                }
                // if extract has a attribute name except "=" then append/nest this name with curr name in form
                //  name1~name2  and so on
                else
                {
                    if (extract != "=")
                    {
                        // its an attribute name
                        attr_name = curr + "~" + extract;
                    }
                }
            }
        }
        std::string query;
        for (int i = 0; i < q; i++)
        {
            std::getline(std::cin, query);
            if (m.find(query) != m.end())
            {
                std::cout << m.find(query)->second << std::endl;
            }
            else
            {
                std::cout << "Not Found!" << std::endl;
            }
        }
        return m;
    }

}; // namespace attribute_parser

namespace Hi
{
    int main()
    {
        std::cout << "fuck you";
        return 0;
    }
};
