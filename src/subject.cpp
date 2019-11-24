////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Definition of some methods for class Subject
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
///
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Averichkina Victoria
// 184-1
// Date:         23.11.2019
////////////////////////////////////////////////////////////////////////////////


#include "subject.h"



namespace xi {


std::ostream& operator<<(std::ostream& outs, const Subject& subj)
{   
    outs << subj.name << ": " << subj.title << "\n";
   
    int index = 0;
    int maxSubj = subj.description.getCapacity();

    while (index < maxSubj && subj.description[index] != "")
        outs << subj.description[index++] << "\n";

    return outs;
}


std::istream& operator>>(std::istream& ins, Subject& subj)
{
    /// для того, чтобы прочитать первые два параметра, а затем начать запись в описание
   int line = -2;
   std::string extra = "";
   while((line!=10)&&(std::getline(ins, extra))&&(!extra.empty()))
   {
       if(line == -2)
       {
           subj.name = extra;
           line += 1;
       }
       else if(line == -1)
       {
           subj.title = extra;
           line += 1;
       }
       else
       {
           subj.description[line] = extra;
           line += 1;
       }
   }

    return ins;
}


} // namespace xi

