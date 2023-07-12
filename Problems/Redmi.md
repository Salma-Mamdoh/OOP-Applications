<html>
<body>
<h2>Problem 1: Function Solver</h2><br>
We need to create a set of classes that allow us to build and modify functions at runtime using tools similar to those in the STL &lt;functional&gt; library. We have an abstract class called Function that has a single function, evaluateAt, which accepts a double as a parameter and returns the value of some function evaluated at that point. We need to write three derived classes of Function and test them:</p>

<ul>
<li>SimpleFunction: This class accepts a regular C++ function or a lambda function that accepts and returns a double. The evaluateAt function returns the value of the stored function evaluated at the parameter.</li>
<li>CompositionFunction: This class accepts two functions and returns the composition of the two functions evaluated at x.</li>
<li>DerivativeFunction: This class accepts a function and a double representing Δx and approximates the derivative of the stored function using the initial value of Δx.</li>
</ul>

<p>We can then write a main program that tests these classes.</p>

<h2>Problem 2: Label Generator</h2><br>
For certain applications, it is useful to be able to generate a series of names that form a sequential pattern. We need to create a tool or label generator that allows the client to define arbitrary sequences of labels, each of which consists of a prefix string coupled with an integer used as a sequence number. We define the label generator as an abstract type called LabelGenerator. To initialize a new generator, the client provides the prefix string and the initial index as arguments to the LabelGenerator constructor. Once the generator has been created, the client can return new labels in the sequence by calling nextLabel on the LabelGenerator. We can then create a new class called FileLabelGenerator which has an extra attribute that is a file name with lines of captions of labels to use in generation. This will override the nextLabel method to take the next label from the file and added it to the generated label that you by calling the parent's nextLabel.</p>

<h2>Problem 3: Document Similarity</h2><br>
We need to define a class called StringSet that will store a set of C++ strings. We use an array or a vector to store the strings. We create a constructor that takes a file name and loads the words in it (ignoring punctuation and turning text to lower case). We write another constructor that takes a string and loads it and breaks it to tokens. We write member functions to add a string to the set, remove a string from the set, clear the entire set, return the number of strings in the set, and output all strings in the set. We overload the + operator to return the union of two StringSet objects. We overload the * operator so that it returns the intersection of two StringSet objects. We also add a member function that computes the similarity between the current StringSet and an input parameter of type StringSet. Similarity is measured by binary cosine coefficient.</p>

<h2>Problem 4: Game of Life</h2><br>
We need to implement the Game of Life cellular automaton proposed by John Horton Conway. The universe of this game is a grid of square cells that could have one of two states: dead or alive. Every cell interacts with its adjacent neighbors, with the following transactions occurring on every step:</p>

<ul>
<li>Any live cell with fewer than two live neighbors dies, as if caused by underpopulation</li>
<li>Any live cell with two or three live neighbors lives on to the next generation</li>
<li>Any live cell with more than three live neighbors dies, as if by overpopulation</li>
<li>Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction</li>
</ul>
</body>
</html>
