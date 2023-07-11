<h2>BigReal Class</h2>
<p>The BigReal class is a C++ class that can hold a real number with an unlimited number of digits and the supporting math functions. The class makes use of the BigDecimalInt class through OOP composition.</p>

<h2>BigDecimalInt Class</h2>
<p>The BigDecimalInt class is a C++ class that represents an integer with an unlimited number of digits. It has several public functions that allow for arithmetic operations and comparisons with other BigDecimalInt objects.</p>

<h2>BigReal Class Interface</h2>
<p>The BigReal class has the following public functions:</p>
<ul>
  <li>BigReal(double realNumber = 0.0): Default constructor that initializes a BigReal object with a default value of 0.0.</li>
  <li>BigReal(string realNumber): Constructor that initializes a BigReal object with a real number in string format. The function validates that the passed parameter is a valid real number.</li>
  <li>BigReal(BigDecimalInt bigInteger): Constructor that initializes a BigReal object with a BigDecimalInt object.</li>
  <li>BigReal(const BigReal& other): Copy constructor.</li>
  <li>BigReal(BigReal&& other): Move constructor.</li>
  <li>BigReal& operator=(BigReal& other): Assignment operator.</li>
  <li>BigReal& operator=(BigReal&& other): Move assignment operator.</li>
  <li>BigReal operator+(BigReal& other): Addition operator that returns the sum of two BigReal objects.</li>
  <li>BigReal operator-(BigReal& other): Subtraction operator that returns the difference between two BigReal objects.</li>
  <li>bool operator<(BigReal anotherReal): Less than operator that compares two BigReal objects and returns a boolean value.</li>
  <li>bool operator>(BigReal anotherReal): Greater than operator that compares two BigReal objects and returns a boolean value.</li>
  <li>bool operator==(BigReal anotherReal): Equality operator that compares two BigReal objects and returns a boolean value.</li>
  <li>int size(): Returns the number of digits in the BigReal object.</li>
  <li>int sign(): Returns the sign of the BigReal object (-1 for negative, 0 for zero, 1 for positive).</li>
  <li>friend ostream& operator<<(ostream& out, BigReal num): Overloads the << operator to output the BigReal object.</li>
  <li>friend istream& operator>>(istream& out, BigReal num): Overloads the >> operator to input the BigReal object.</li>
</ul>

<h2>Design</h2>
<p>The BigReal class makes use of OOP composition to store a real number as a combination of two BigDecimalInt objects – one for the integer part and one for the fractional part. The class also includes functions to handle arithmetic operations and comparisons with other BigReal objects.</p>
<p>The class is designed in a header file and an implementation file to separate the interface from the implementation. The string parameter passed in the constructor is validated to ensure that it is a valid real number.</p>

<h2>Example Usage</h2>
<pre>
<code>
BigReal n1("11.9000000000000000000000000000000001");
BigReal n2("2333333333339.1134322222222292");
BigReal n3 = n1 + n2;
cout << n3 << endl; // Output: 2333333333351.0134322222222292

n3 = n3 + BigReal(0.9);
cout << n3 << endl; // Output: 2333333333351.9134322222222292
</code>
</pre>
