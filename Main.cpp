// OOP Project
#include <iostream>
#include <iomanip>
class account
{
private:
  int money = 0;
  std::string PV_Username = "Sorrawit";
  std::string PV_Password = "1234";

public:
  account(std::string user, std::string pass);
  int deposit(int deposit_money);
  int withdraw(int withdraw_money);
  void deleteAcc();
  void displayLoop();
  int getMoney() { return money; }
};

void login();

int main(int argc, char *argv[])
{
  std::cout << "BANK SYSTEM BY SORRAWIT\n";
  std::cout << "Please Login\n";
  login();

  std::cin.get();
  return 0;
}

void login()
{
  std::string username;
  std::string password;
  std::cout << "Username : ";
  std::cin >> username;
  std::cout << "Password : ";
  std::cin >> password;
  account acc(username, password);
}

account::account(std::string user, std::string pass)
{
  if (user == PV_Username && pass == PV_Password)
  {
    std::cout << "Login Success!\n";
    displayLoop();
  }
  else
  {
    std::cout << "Incorrect Username or Password.\nPlease try again.\n";
    login();
  }
}

int account::deposit(int deposit_money)
{
  money += deposit_money;
  return money;
}

int account::withdraw(int withdraw_money)
{
  money -= withdraw_money;
  return money;
}

void account::deleteAcc()
{
  PV_Username.clear();
  PV_Password.clear();
}

void account::displayLoop()
{
  char ch;

  do
  {
    std::cout << "\t--------MAIN MENU--------\n";
    std::cout << "\tAccount Statement : \t1\n";
    std::cout << "\tDeposit : \t\t2\n";
    std::cout << "\tWithdraw : \t\t3\n";
    std::cout << "\tDelete Account : \t4\n";
    std::cout << "\tExit : \t\t\t5\n";
    std::cout << "Enter menu: ";
    std::cin >> ch;
    switch (ch)
    {
    case '1':
      std::cout << "Account Statement : " << getMoney() << '\n';
      break;
    case '2':
      int de_money;
      std::cout << "Deposit Money\n";
      std::cout << "Enter the amount of money you want to deposit. : ";
      std::cin >> de_money;
      deposit(de_money);
      std::cout << "It's Done!\n";
      break;
    case '3':
      int wi_money;
      std::cout << "Deposit Money\n";
      std::cout << "Enter the amount of money you want to withdraw. : ";
      std::cin >> wi_money;
      withdraw(wi_money);
      std::cout << "It's Done!\n";
      break;
    case '4':
      char delchar;
      std::cout << "Delete Account\n";
      std::cout << "Are you sure? [Y/n]";
      std::cin >> delchar;
      if (delchar == 'Y' || delchar == 'y')
      {
        std::cout << "Deleting Your Account.\n";
        deleteAcc();
      }
      std::cout << "It's Done!\n";
      break;
    default:
      std::cout << "Please Enter Number from 1-5 only.\n";
      break;
    }
  } while (ch != '5');
  if (ch == '5')
  {
    std::cout << "Logging Out...\n";
  }
}