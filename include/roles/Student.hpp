#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "User.hpp"
#include "foodservice/Reservation.hpp"
#include "foodservice/ReservationJsonSerialized.hpp"
#include "config/AppConfig.hpp"
#include <nlohmann/json.hpp>
#include <vector>
using json = nlohmann::json;

using namespace std;

class Reservation;

class Student : public User
{
public:
    Student() : User(), _balance(0.0f), _isActive(false) {}
    Student(string studentID, string name, string lastName, string password);

    // Student-specific methods
    void reserveMeal();
    void cancelReservation();

    // Override print method
    void print() const;

    // Getters
    bool isActive() const { return _isActive; }
    string getStudentID() const { return _studentID; }
    string getEmail() const { return _email; }
    string getPhone() const { return _phone; }
    float getBalance() const { return _balance; }
    vector<Reservation> getReserves() const { return this->_reserves; };

    // Setters
    void setStudentID(string studentID) { _studentID = studentID; }
    void setEmail(string email) { _email = email; }
    void setPhone(string phone) { _phone = phone; }
    void setBalance(float balance) { _balance = balance; }
    void setReserves(vector<Reservation> reserves)
    {
        this->_reserves = reserves;
    }

    // Activation and deactivation
    void activate() { _isActive = true; }
    void deactivate() { _isActive = false; }

    // Other member functions
    bool checkPassword(string password);
    void setHashedPassword(string password);

private:
    string _studentID;
    string _email;
    string _phone;
    float _balance;
    bool _isActive;
    vector<Reservation> _reserves;
};
namespace nlohmann
{

    template <>
    struct adl_serializer<Student>
    {
        // Serialize Student to JSON
        static void to_json(json &j, const Student &student)
        {
            j = json{
                {"student-id", student.getStudentID()},
                {"name", student.getName()},
                {"lastname", student.getLastName()},
                {"hash-password", student.getHashedPassword()},
                {"email", student.getEmail()},
                {"phone", student.getPhone()},
                {"balance", student.getBalance()},
                {"isActive", student.isActive()},
                {"reservations", student.getReserves()}};
        }

        // Deserialize JSON to Student
        static void from_json(const json &j, Student &student)
        {
            student.setStudentID(j.at("student-id").get<string>());
            student.setName(j.at("name").get<string>());
            student.setLastName(j.at("lastname").get<string>());
            student.setHashedPassword(j.at("hash-password").get<string>());
            student.setEmail(j.at("email").get<string>());
            student.setPhone(j.at("phone").get<string>());
            student.setBalance(j.at("balance").get<float>());
            if (j.contains("isActive"))
            {
                if (j.at("isActive").get<bool>())
                    student.activate();
                else
                    student.deactivate();
            }

            // Deserialize reservations
            if (j.contains("reservations"))
            {
                student.setReserves(j.at("reservations").get<vector<Reservation>>());
            }
        }
    };

}

#endif // STUDENT_HPP