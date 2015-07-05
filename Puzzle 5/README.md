#Puzzle 5

##Starting
This puzzle gave us a grid of squares with 4 doges - some of them green and clickable, the others red and unclickable.

#Experimenting
Clicking around randomly eventually seemed to give us certain repeated patterns. For example, clicking up and then down (or vice versa) gave you the same pattern of squares as if you hadn't done that at all. Same with left/right. The reason for this became very clear and obvious, but we didn't know why yet.

Another part of the puzzle involved the images that showed up. These were numbered and had doge-related words followed by a letter.

#The Maze Revelation
We had the revelation that this was actually a maze, where red doges represented walls and green doges were places where you could move. With this knowledge, it was simple enough to implement a graph traversal algorithm to try and find all the relevant images.

Because of the uncertainty of the size of the maze (possibly infinite if generated according to an algorithm), breadth-first search was used (since it is capable of handling graphs of infinite size, unlike depth-first search), along with a dictionary that mapped coordinates to a value if that coordinate was visited. As it turns out, the entire maze is about 20x20 in size, so the maze algorithm finds all images in about 30 seconds (most of this time due to network requests).

##Unscrambling the letters
After finding all the images, we were left with 9 letters. Putting them all in as-is didn't work, and neither did putting in their corresponding symbols.

We noticed that "much" and "such" were words in scrambled form in those 9 letters. Plugging in the remaining letters into a word unscrambler gave us the final answer.
