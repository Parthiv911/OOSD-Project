#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Person
{
public:
    string name;

    string mobileNumber;

    string emailAddress;

    // setter and getter methods for name of person
    string getName()
    {

        return this->name;
    }

    void setName(string name)
    {

        this->name = name;
    }

    // setter and getter methods for mobile number of person
    string getmobileNumber()
    {

        return this->mobileNumber;
    }

    void setmobileNumber(string mobileNumber)
    {

        this->mobileNumber = mobileNumber;
    }

    // setter and getter methods for email of person
    string getEmail()
    {

        return this->emailAddress;
    }

    void setEmail(string emailAddress)
    {

        this->emailAddress = emailAddress;
    }
};

class Show
{

private:
    string showTime;

    string title;

    int orchSeat;

    int midSeat;

    int balconySeat;

    int sales;

    int PriceOrch_and_Mid;

    int PriceBalconySeat;

public:
    string GetTitle()
    {

        return this->title;
    }

    void setTitle(string title)
    {

        this->title = title;
    }

    int getPriceOrch_and_Mid()
    {

        return this->PriceOrch_and_Mid;
    }

    void setPriceOrch_and_Mid(int p)
    {

        this->PriceOrch_and_Mid = p;
    }

    int getPriceBalconySeat()
    {

        return this->PriceBalconySeat;
    }

    void setPriceBalconySeat(int p)
    {

        this->PriceBalconySeat = p;
    }

    string getShowTime()
    {

        return this->showTime;
    }

    void setShowTime(string st)
    {

        this->showTime = st;
    }

    int getOrchestraSeatAvailable()
    {

        return this->orchSeat;
    }

    void setOrchestraSeatAvailable(int s)
    {

        this->orchSeat = s;
    }

    int getMidSeatAvailable()
    {

        return this->midSeat;
    }

    void setMidSeatAvailable(int s)
    {

        this->midSeat = s;
    }

    int getBalconySeatAvailable()
    {

        return this->balconySeat;
    }

    void setBalconySeatAvailable(int s)
    {

        this->balconySeat = s;
    }

    int getSales()
    {

        return this->sales;
    }

    void setSales(int s)
    {

        this->sales = s;
    }
};

class SalesPerson : public Person
{

private:
    static long int T_id;

    long int id;

    string password;

public:
    long int getId()
    {

        return this->id;
    }

    void SetId(long int id)
    {

        this->id = id;
    }
    string getUserName()
    {

        return this->name;
    }

    void setUserName()
    {

        string usname;

        cout << "Enter new user name" << endl;

        cin >> usname;

        this->name = usname;
    }
    string getPassWord()
    {

        return this->password;
    }

    void setPassword()
    {

        cout << "Enter new Password" << endl;

        string Pas;

        cin >> Pas;

        this->password = Pas;
    }
    int bookTicket(int a, Show &s)
    {

        if (a == 0)
        {

            int st = s.getOrchestraSeatAvailable();

            if (st)

            {

                s.setOrchestraSeatAvailable(st - 1);

                int sl = s.getSales();

                s.setSales(sl + 1);

                return T_id++;
            }

            else

            {

                cout << "Not Available" << endl;

                return 0;
            }
        }

        else if (a == 1)

        {

            int st = s.getMidSeatAvailable();

            if (st)

            {

                s.setMidSeatAvailable(st - 1);

                int sl = s.getSales();

                s.setSales(sl + 1);

                return T_id++;
            }

            else

            {

                cout << "Not Available" << endl;

                return 0;
            }
        }

        else

        {

            int st = s.getBalconySeatAvailable();

            if (st)

            {

                s.setBalconySeatAvailable(st - 1);

                int sl = s.getSales();

                s.setSales(sl + 1);

                return T_id++;
            }

            else

            {

                cout << "Not Available" << endl;

                return 0;
            }
        }

        return 0;
    }

    void cancellation(int TransId, int typeOfSeat)
    {

        int st;

        Show s;

        if (typeOfSeat == 0)

        {

            st = s.getOrchestraSeatAvailable();

            s.setOrchestraSeatAvailable(st + 1);
        }

        else if (typeOfSeat == 1)

        {

            st = s.getMidSeatAvailable();

            s.setMidSeatAvailable(st + 1);
        }

        else

        {

            st = s.getBalconySeatAvailable();

            s.setBalconySeatAvailable(st + 1);
        }

        int sales = s.getSales();

        s.setSales(sales - 1);
    }
};

long int SalesPerson::T_id = 0;

class ShowManager : public Person
{

private:
    map<long int, SalesPerson> Salesperson;

    vector<Show> showDetails;

    static long int id;

public:
    void getSalesPersonsList()
    {
        cout << 2;
        for (auto data : Salesperson)

        {

            cout << "Name           : " << data.second.name << endl;

            cout << "Email          : " << data.second.emailAddress << endl;

            cout << "MobileNumber   : " << data.second.mobileNumber << endl;

            cout << "Id             : " << data.second.getId() << endl;
        }
    }

    void getShowList()
    {

        for (auto &data : showDetails)

        {

            cout << endl;

            cout << "Title                 : " << data.GetTitle() << endl;

            cout << "Front Seats        : " << data.getOrchestraSeatAvailable() << endl;

            cout << "Middle Seats         : " << data.getMidSeatAvailable() << endl;

            cout << "Balcony Seats     : " << data.getBalconySeatAvailable() << endl;

            cout << "Front and Middle Seat Price   : " << data.getPriceOrch_and_Mid() << endl;

            cout << "Balcony Seat Price    : " << data.getPriceBalconySeat() << endl;

            cout << "Show timing    : " << data.getShowTime() << endl;
        }

        cout << endl;
    }

    void setSalesPerson(map<int, SalesPerson> &mp)
    {

        string name, email;

        string mobile;

        SalesPerson sp;

        cout << "Enter name of Sales Person            : ";

        cin >> name;

        cout << "Enter email of Sales Person           : ";

        cin >> email;

        cout << "Enter Mobile Number of Sales Person   : ";

        cin >> mobile;

        sp.setName(name);

        sp.setEmail(email);

        sp.SetId(id);

        sp.setmobileNumber(mobile);

        Salesperson[id] = sp;
        mp[id] = sp;
        cout << " SUCCESSFULLY ADDED:your id is : " << id << endl;

        id++;
    }

    void RemoveSalesPerson(long int id)
    {

        auto it = Salesperson.find(id);

        if (it == Salesperson.end())

        {

            cout << "This SalesPerson does not exist,cant remove!\n";
        }

        else

        {

            Salesperson.erase(id);

            cout << "Successfully removed SalesPerson with id:" << id << "\n";
        }
    }

    void setShowList(vector<Show> &v)
    {

        string title, showTime;

        int orchSeat, midSeat, balconySeat, PriceOrch_and_Mid, PriceBalconySeat;

        Show new_show;

        cout << "Enter Title of The Show                      : ";

        cin >> title;

        cout << "Enter Number of Orchestra (Front) Seats        : ";

        cin >> orchSeat;

        cout << "Enter Number of Mezzanine (Middle) Seats         : ";

        cin >> midSeat;

        cout << "Enter Number of Balcony (Back) Seats            : ";

        cin >> balconySeat;

        cout << "Enter Price for Orchestra and Mezzanine Seats  for the show   : ";

        cin >> PriceOrch_and_Mid;

        cout << "Enter Price for Balcony Seats  for the show    : ";

        cin >> PriceBalconySeat;

        cout << "Enter show timing for the show    : ";

        cin >> showTime;

        cout << " SUCCESSFULLY ADDED " << endl;

        new_show.setTitle(title);

        new_show.setOrchestraSeatAvailable(orchSeat);

        new_show.setMidSeatAvailable(midSeat);

        new_show.setBalconySeatAvailable(balconySeat);

        new_show.setSales(0);

        new_show.setPriceOrch_and_Mid(PriceOrch_and_Mid);

        new_show.setPriceBalconySeat(PriceBalconySeat);

        new_show.setShowTime(showTime);

        showDetails.push_back(new_show);

        v.push_back(new_show);
    }
};

long int ShowManager::id = 77;

int main()
{

    cout << "*****************************************************************************"
         << endl;

    cout << "                   THEATRE MANAGEMENT SYSTEM                      " << endl;

    cout << "*****************************************************************************"
         << endl
         << endl;

    ShowManager obj;

    map<int, SalesPerson> SalesPersonList;

    vector<Show> ShowList;

    multiset<string> users;

    multimap<string, long int> forShowBooking;

    int input;

    while (1)

    {

        cout << "--------------------------------HOME PAGE--------------------------------------"
             << endl
             << endl;

        cout << "Input As:" << endl;

        cout << 1 << ".Show Manager" << endl;

        // cout<<2<<". Sales Person"<<endl;
        cout << 2 << ".Customer" << endl;

        cout << 3 << ".exit" << endl
             << endl;

        cout << "Enter in the system as:\nPress 1 for ShowManager\nPress 2 for Customer\nPress 3 for exit\n";

        cin >> input;

        if (input == 3)

        {

            cout << endl
                 << "Quiting the system..." << endl;

            usleep(600000);
        }

        else if (input > 3)

        {

            cout << endl
                 << "OOPS!Invalid Input,Enter your Choice again" << endl;

            continue;
        }

        else

        {

            cout << endl
                 << "loading the system..." << endl;

            usleep(500000);
        }

        if (input == 1)

        {

            while (1)

            {

                cout << endl
                     << "--------------------OPENED SHOW MANAGER PORTAL------------------------------"
                     << endl
                     << endl;

                int choice_SM;

                cout << 1 << ". Get Sales Person List" << endl;

                cout << 2 << ". Add new Sales Person" << endl;

                cout << 3 << ". Get Show List" << endl;

                cout << 4 << ". Add new Show" << endl;

                cout << 5 << ". Log Out" << endl
                     << endl;

                cout << "Show-Manager,Please Enter your choice : ";

                cin >> choice_SM;
                ShowManager s;
                if (choice_SM == 1)

                    s.getSalesPersonsList();

                else if (choice_SM == 2)

                    s.setSalesPerson(SalesPersonList);

                else if (choice_SM == 3)

                    s.getShowList();

                else if (choice_SM == 4)

                    s.setShowList(ShowList);

                else

                    break;
            }
        }

        else if (input == 2)

        {

            cout << endl
                 << "------------------------OPENED CUSTOMER PORTAL-------------------------------"
                 << endl
                 << endl;

            cout << "Please Enter Username : ";

            string userName;

            cin >> userName;

            if (users.find(userName) == users.end())

                users.insert(userName);

            cout << "Enter Your Password : ";

            string Password;

            cin >> Password;

            cout << endl
                 << "logging in ..." << endl;

            usleep(600000);

            while (1)

            {

                int choice_C;

                cout << 0 << "Show My bookings" << endl;

                cout << 1 << "check shows" << endl;

                cout << 2 << "book show" << endl;

                cout << 3 << "cancel ticket" << endl;

                cout << 4 << "Log out" << endl
                     << endl;

                cout << userName << ",Please Enter Your Choice : ";

                cin >> choice_C;

                if (choice_C == 0)

                {

                    auto tid = forShowBooking.find(userName);

                    if (tid == forShowBooking.end())

                    {

                        cout << "--------------------------------------------------------"
                             << endl;

                        cout << "|                Sorry!You have No booking !!!                |"
                             << endl;

                        cout << "--------------------------------------------------------"
                             << endl
                             << endl;
                    }

                    else

                    {

                        // int id = users[userName].id;

                        // SalesPerson sw = SPList[id];

                        // int tid = users[userName].T_Id;

                        // sw.Ticket (tid);
                    }
                }

                else if (choice_C == 1)

                {

                    for (int i = 0; i < ShowList.size(); i++)

                    {

                        Show so_obj = ShowList[i];

                        string title = so_obj.GetTitle();

                        string time = so_obj.getShowTime();

                        int orch = so_obj.getOrchestraSeatAvailable();

                        int mid = so_obj.getMidSeatAvailable();

                        int Bal = so_obj.getBalconySeatAvailable();

                        int pa = so_obj.getPriceOrch_and_Mid();

                        ;

                        int pb = so_obj.getPriceBalconySeat();

                        cout << endl;

                        cout << "Show Number              : " << i + 1 << endl;

                        cout << "Title                     : " << title << endl;

                        cout << "Fronts Seats Available : " << orch << endl;

                        cout << "Mid Seats Available : " << mid << endl;

                        cout << "Balcony Seats Available  : " << Bal << endl;

                        cout << "Price for front/mid Seat      : " << pa << endl;

                        cout << "Price for Balcony Seat       : " << pb << endl

                             << endl;
                    }
                }

                else if (choice_C == 2)

                {

                    if (ShowList.empty())

                    {

                        cout << "Sorry,No Shows available" << endl;
                    }

                    else

                    {

                        cout << "Choose Show from the list" << endl;

                        int ShowNumber;

                        cin >> ShowNumber;

                        // int sz = SPList.size();
                        // int id = rand()%(sz)+7893;
                        int st_type;

                        cout << "Choose seat type : ";

                        cout << 0 << " for front seats" << endl;

                        cout << 1 << " for mid seats" << endl;

                        cout << 2 << " for balcony seats" << endl;

                        cin >> st_type;

                        SalesPerson obj_SP;

                        long int TID =
                            obj_SP.bookTicket(st_type, ShowList[ShowNumber - 1]);

                        if (TID)

                        {

                            forShowBooking.insert({userName, TID});

                            cout << "Booking........." << endl;

                            usleep(500000);

                            cout << "--------------------------------------------------------"
                                 << endl;

                            cout << "|         Congrats!!!! Booking Confirmed.               |"
                                 << endl;

                            cout << "--------------------------------------------------------"
                                 << endl
                                 << endl;
                        }

                        else

                            cout << "Sorry !! the service you are looking for is not available currently,Try after sometime\n";
                    }
                }

                else if (choice_C == 3)

                {

                    auto tid = forShowBooking.find(userName);

                    if (tid == forShowBooking.end())

                    {

                        cout << "--------------------------------------------------------"
                             << endl;

                        cout << "|                You have No booking for cancellation!!!                |"
                             << endl;

                        cout << "--------------------------------------------------------"
                             << endl
                             << endl;
                    }

                    else

                    {

                        SalesPerson obj_SP;

                        int stp;

                        cout << "Enter your seat type (0/1/2):";

                        cin >> stp;

                        obj_SP.cancellation(tid->second, stp);

                        forShowBooking.erase(tid);

                        cout << " Cancelling ......" << endl;

                        usleep(500000);

                        cout << "Cancelled\n";

                        cout << "we will initiate the refund process within 24 hrs acoording to our refund policy."
                             << endl;
                    }
                }

                else

                    break;
            }
        }

        else

            break;
    }

    return 0;
}
