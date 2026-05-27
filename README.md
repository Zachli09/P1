Write a program to help a store track the money it made in a day.
• When the program starts, the user must login to the system. From main, give the user
three chances to login by asking for a username and password. Use a loop to determine
how many attempts the user has made. Control the loop with a call to the login function.
o login: This function accepts the user’s provided login info and returns a bool
indicating if the login was successful. For now, use dummy data for the correct
login info: the username should be “user” and the password should be “1234”.
• In main, each time the user fails to login correctly, let them know how many more
attempts they have until they are locked out of the system. After the third failed attempt,
end the program.
• If the user logs in, create an accumulator to track the running total of money made that
day. In a menu-based system, give the user the following options: Add a sale, make
change, issue a refund, or quit. Each choice should call a function:
o addSale: Ask the user to enter the amount of a sale. You may assume the user
will enter numeric data when this option is selected. After the sale amount is
entered, the program should add 6.5% to the sale amount for sales tax and
return the result.
o makeChange: This function helps the user give change to a customer paying in
cash. Ask how much money the customer provided and how much they owe. For
simplicity, both can be integers. After the values have been entered:
▪ If the amount the customer paid is less than the amount owed, tell the
user the customer needs to provide more money.
▪ If the amounts are equal, tell the user the customer does not need
change.
▪ Otherwise, determine how to provide change for the customer with the
least number of bills possible. Assume the store has an unlimited number
of $20, $10, $5, and $1 bills. For example, if the customer pays $100 and
owes $53, the program should tell the user to provide two $20, one $5,
and two $2 bills.
o giveRefund. Ask the user how much of a refund is being given. You may assume
the user will enter numeric data. The amount the user enters should be deducted
from the running total (no need to calculate tax). Return the new running total
after the refund has been applied.
▪ However: Do not perform the deduction if it would cause the running total
to go below $0. Instead, print a message telling the employee the refund
cannot be issued and instructing them to speak to their manager.
o Quit the program. When the user selects this option, the total amount entered in
sales should print to the screen. Then the program should end.
