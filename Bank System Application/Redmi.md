<!DOCTYPE html>
<html>
<head>
	
</head>
<body>
	<h1>Bank System Application</h1>
	<p>This is a simple banking application that allows a bank employee to create bank accounts for clients, list all available bank accounts, and perform operations like withdrawing and depositing money.</p>

<h2>Classes</h2>
	<p>The application has four main classes:</p>

<h3>BankApplication</h3>
	<p>This is the main class that runs the application. It has the following methods:</p>
	<ul>
		<li>createAccount()</li>
		<li>listClientsAndAccounts()</li>
		<li>withdrawMoney()</li>
		<li>depositMoney()</li>
		<li>displayMenu()</li>
		<li>run()</li>
	</ul>

<h3>Client</h3>
	<p>This class holds the basic information of a client like his name, address, and phone number. It has the following attributes:</p>
	<ul>
		<li>name</li>
		<li>address</li>
		<li>phone</li>
		<li>account</li>
	</ul>

<h3>BankAccount</h3>
	<p>This is the base class for all bank accounts. It has the following attributes:</p>
	<ul>
		<li>accountId</li>
		<li>balance</li>
	</ul>
	<p>It has the following methods:</p>
	<ul>
		<li>BankAccount()</li>
		<li>BankAccount(double balance)</li>
		<li>getAccountId()</li>
		<li>getBalance()</li>
		<li>setBalance(double balance)</li>
		<li>withdraw(double amount)</li>
		<li>deposit(double amount)</li>
	</ul>

<h3>SavingsBankAccount</h3>
	<p>This class extends the BankAccount class using inheritance. It has additional attributes and methods.</p>
	<ul>
		<li>minimumBalance</li>
		<li>accountType</li>
	</ul>
	<p>It has the following methods:</p>
	<ul>
		<li>SavingsBankAccount(double balance, double minimumBalance)</li>
		<li>getMinimumBalance()</li>
		<li>setMinimumBalance(double minimumBalance)</li>
		<li>withdraw(double amount)</li>
		<li>deposit(double amount)</li>
	</ul>

<h2>Conclusion</h2>
	<p>This banking application demonstrates the use of OOP concepts like inheritance and polymorphism to model different types of bank accounts and their operations. It also shows how these classes can be used together to build a complete application with a main menu and user input.</p>
</body>
</html>
