#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. 학생 정보 structure 구성
struct Student {
   string name;
   long id = 0;
   int midterm = 0;
   int final = 0;

   // 중간고사, 기말고사 평균을 계산하는 함수
   long average() const {
      return (midterm + final) / 2;

   }

   // 학생 정보를 출력하기 위한 friend함수
   // 객체를 옮기는 << 연산자 만들기
   friend std::ostream& operator << (std::ostream& os, const Student& stu) {
      os << stu;
      return os;
   }


   /*

   friend std::ostream& operator << (std::ostream& os, Student& stu) {
      os << stu;
      cout << "[" << stu.name << " " << stu.id << " " << stu.average() << "]" << "\n";
      return os;
   }
      */

};



   int main() {
      // 2. 학생 정보 배열 구현 (vector 사용)
      std::vector<Student> studentsArr;
      bool endCodeEntered = false; // flag


         // 3. 성적 관리 프로그램
      while (!endCodeEntered) {

         // a. 학생 리스트 출력
         cout << "<학생 리스트>" << "\n";

         for (auto i = studentsArr.begin(); i < studentsArr.end(); i++) {
            cout << *i << "\n";
         }
         cout << "\n";
         

         // b. command 입력 받기 (1부터 8까지 입력 가능)
         int code;
         cout << "코드 입력: ";
         cin >> code;
         cout << "\n";

         switch (code) {

         case 1: // 학생 정보 추가
         {
            cout << "-------------------------------------------------" << "\n";
            cout << "학번, 이름, 중간고사 점수, 기말고사 점수를 입력 " << "\n";
            cout << "주의! 이때 이름은 영어로 하고, space나 tab은 포함하지 않아야 한다. " << "\n";


            Student student;
            cout << "학번: ";
            cin >> student.id;
            cout << "이름: ";
            cin >> student.name;
            cout << "중간고사 점수: ";
            cin >> student.midterm;
            cout << "기말고사 점수: ";
            cin >> student.final;
            cout << "-------------------------------------------------" << "\n";

            studentsArr.push_back(student); // 입력받으면 push_back을 통해 array 맨 뒤에 data추가

         } cout << "case1 clear\n";  
         break;

         case 2: // 학생 정보 삭제
         {
            int toFind; // 삭제하고자 하는 학번
            cout << "삭제하고자 하는 학번 입력: ";
            cin >> toFind;

            auto found = std::find_if(studentsArr.begin(), studentsArr.end(),
               [toFind](const Student& stu) {return stu.id == toFind; }); // found는 find_if의 반환값이므로 iterator

            // 해당 학생이 없는 경우
            if (found == studentsArr.end()) {

               cout << "Not found\n";
               break;
            }
            else {
               studentsArr.erase(found); // 삭제
            }


         } break;


         case 3: // 특정 학생 중간고사 점수 수정
         {
            Student student;
            cout << "특정 학생의 학번과 중간고사 점수 입력: ";
            cin >> student.id >> student.midterm;
            int toFind = student.midterm;

            auto found = std::find_if(studentsArr.begin(), studentsArr.end(),
               [toFind](const Student& stu) {return stu.midterm == toFind; }); // found는 find_if의 반환값이므로 iterator

            // 해당 학생이 없는 경우
            if (found == studentsArr.end()) {

               cout << "Not found\n";
               break;
            }
            else {
               cout << "수정할 중간고사 점수 입력: ";
               cin >> found->midterm;
            }


         } break;


         case 4: // 특정 학생 기말고사 점수 수정
         {

            Student student;
            cout << "특정 학생의 학번과 기말고사 점수 입력: ";
            cin >> student.id >> student.final;
            int toFind = student.final;

            auto found = std::find_if(studentsArr.begin(), studentsArr.end(),
               [toFind](const Student& stu) {return stu.final == toFind; }); // found는 find_if의 반환값이므로 iterator

            // 해당 학생이 없는 경우
            if (found == studentsArr.end()) {

               cout << "Not found\n";
               break;
            }
            else {
               cout << "수정할 기말고사 점수 입력: ";
               cin >> found->final;
            }

         } break;

         case 5: // 학번 순으로 정렬
         {
            cout << "학번 순으로 정렬" << "\n";
            std::sort(studentsArr.begin(), studentsArr.end(),
               [](const Student& a, const Student& b) {return a.id < b.id; });

         } break;

         case 6: // 이름 순으로 정렬
         {
            cout << "이름 순으로 정렬" << "\n";
            std::sort(studentsArr.begin(), studentsArr.end(),
               [](const Student& a, const Student& b) {return a.name < b.name; });

         } break;


         case 7: // 최종성적 순으로 정렬
         {
            cout << "최종성적 순으로 정렬" << "\n";
            std::sort(studentsArr.begin(), studentsArr.end(),
               [](const Student& a, const Student& b) {return a.average() < b.average(); });

         } break;


         case 8:
         {
            endCodeEntered = true;

         } break;


         default:
            cout << "Wrong command" << endl;
         }

         return 0;
      }

   };

