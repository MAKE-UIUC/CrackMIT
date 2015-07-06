#Puzzle 3

At this point, we were a little disappointed to say the least. The answers to the last two puzzles were _doge-eque_ phrases. We wonder just how guessable these answers might be, and whether writing a program to guess the phrases might be easier.

We don’t quite remember why we didn’t go down that path or who shot the idea down. Personally, I think each one of us had such an extensive arsenal to destroy that idea that we simply didn’t have to mention it. The idea simply evaporated.

##Starting
Hitting the link for Puzzle 3 took us to a page which looked like:

![Screen](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%203/number.png)

```
doge loves squares. much love that he got many tiles to decorate his room.

5642034919813852852422781908617467139461193917486713805365683884050791685329043541497496706716395853950507714645119528696115600806682

tiles to be exact.
```
Given the URL of this page, it was clear that this number was calculated based on the user’s github name.

#Factorize? Many-to-One?
What could this possibly be? It was clear from the discussion on #puzzle-3-discuss in Slack that the popular opinion was that of factorization. There were also opinions that though the numbers were different, the final answer would be the same for everyone. This actually worked well with the factorization argument – perhaps there’s a GCD across these numbers.

This wasn’t going to be easy. This is a 441 bit number. A quick Google search revealed that when RSA 155 (512 bit) was first factored in 1999, it took 6 months. Oh dear…

 We spent the next hour or so trying to factor this number. Once this was done, we realized that the factors weren’t the answer were looking for and there wasn’t a GCD across the numbers we found.

##441 Bit
Perhaps we were going about this wrong. Could HackMIT really expect us to try to factor (for our British-leaning team member: factorize) this? If anything, the puzzles seem to be emulating security through obscurity. What were we missing?

We read the text on the page again: doge loves squares. Aha – Squares. 441 is 21 squared.
We immediately expressed the number as a binary string and arranged the string in a 21x 21 grid (simply wrap the string at each 21st digit). 

And that’s when we saw it – a QR Code!

##Reading the QR Code
The code couldn’t be read off just that binary. We tried a couple of quick forms of highlighting before realizing that we’d have to render the QR code better before being able to read it.

This is where our method became truly comic. Of all the methods that we tried, the one that worked fastest was Adobe After Effects. Yes, we used a nuclear weapon to target a paper towel. In seconds, we got the following wobbly (but totally scan-able) render.

![Wobbly QW](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%203/Initial%20QR.png)

The scan read - `amaze swim`. We knew that was our answer because it was another ridiculous doge-phrase. W never thought we’d be so relived to read doge speak.

###Improved Method
Because we’re from UIUC, we couldn’t possibly leave this solution in such an abismal state. After we completed the puzzle, we extended the program we used to express the number as a binary string, to go all the way and render the QR code nicely. 
