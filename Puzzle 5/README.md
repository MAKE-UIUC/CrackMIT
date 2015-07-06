#Puzzle 5

##Starting
This puzzle gave us a grid of squares. Four of these squares contained a picture of doge. Some of these squares had green backgrounds and were clickable, and the others were red and weren’t clickable.

![Screen](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%205/initial.png)

##Experimenting
We didn’t really know what was going on at this point. Clicking the clickable doges seemed to change the state of the grid but the page’s source didn’t seem to help much. Furthermore, with the little information we had of the puzzle, the effect of clicking the green doges seemed to be non-deterministic. 

###All Greens?

The non-deterministic looking nature of the puzzle along with the chatter in #puzzle-5-discuss (where people reported brute-forcing the puzzle) got us to believe that the puzzle would be solved if we could get all the doges to either the green or the red state. Why should this be difficult? Well, the non-deterministic nature of-course.

![4 Greens State](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%205/4_greens.png)

We quickly realized that this may not be the case, as we stumbled upon the 4 greens state fairly quickly. Back to the metaphorical drawing board. `Spoiler: the 4 red state is absolutely impossible`.

###Repeating Patterns

Clicking around arbitrarily seemed to eventually give us certain repeated patterns. For example, clicking up and then down (or vice versa) gave you the same pattern of squares as if you hadn't done so at all. Same with left/right. Although we didn't understand why this was happening at the time, the reason for this became very clear and obvious soon after.

Another part of the puzzle involved the images that showed up. These were numbered and had doge-related words followed by a letter.

##It’s a Maze!
We had the revelation that this was actually a maze, where red doges represented walls and green doges were places where you could move. With this knowledge, it was simple enough to implement a graph traversal algorithm to try and find all the relevant images.

Because of the uncertainty of the size of the maze (possibly infinite if generated according to an algorithm), breadth-first search was used (since it is capable of handling graphs of infinite size, unlike depth-first search), along with a dictionary that mapped coordinates to a value if that coordinate was visited. As it turns out, the entire maze is about 20x20 in size, so the maze algorithm finds all images in about 30 seconds (most of this time due to network requests).

##The Answer?

After finding all the images, we were left with 9 letters. Putting them all in as-is didn't work, and neither did putting in their corresponding symbols.

We noticed that we could unscramble some of the nine letters to make the words: "much" and "such". Plugging in the remaining letters into a word un-scrambler gave us the final answer: `much snarl`.

