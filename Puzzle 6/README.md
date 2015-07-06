#Puzzle 6

##Starting
This puzzle gave us a link to a [Github repo](https://github.com/dogeunderground/stronghold) with some code written for Node.js/Express.

In it we found `validator.js`, which by pure luck we had found in the search for the answer to Puzzle 1. (Viewing the source to dogemit.party gives a list of Github usernames, and one of those Github users has [this repo](https://github.com/ehzhang/stronghold) which is a fork of Puzzle 6.)

##The Checksum
`validator.js` makes use of a few criteria to validate passwords given to it. They are as follows:

* must be alphabetical (no numbers, symbols, spaces, etc)
* must be of length 10 or greater
* must be of even length
* the subsequence of every even character (0 indexed) must pass the checksum (== 0x0000)
* the left half of the password must pass the checksum (== 0xd06e)
* the right half of the password must pass the checksum (== 0xf00d)

The first 3 requirements are easy to satisfy. The last 3, not so much. The checksum has 65536 possible results and this means that only one in every \~2.8 \* 10\^14 passwords will work.

##The Bruteforcer
Luckily, as part of trying to solve "Puzzle 1", we had already written most of the basis for our Puzzle 6 bruteforcer. The original version, `bruteforcer.cpp`, was written in Visual Studio C++ and would iterate in a for loop, mapping the loop variable to a string and running it against all 3 checksum tests. If it passed any one of them, then that string would be recorded in one of three arrays, which would then be saved to files. This original version ran on a single thread and managed to run through all 52^6 possibilities in about 1.5 hours, giving us about 1 million strings in total.

Apparently there are faster ways to do this, but because we had the code written already, we decided to go forward with the bruteforce approach.

##Concatenating the Strings
The second part of the bruteforce involves finding a matching string out of all three arrays. Due to the non-uniform string distribution with regards to the checksum, this was actually not as straight-forward as it appeared.

The first approach involved performing a binary search on the even characters of every combination of left and right. Due to a bug in the binary search, however, the first result we got was incorrect. Attempting to try again would involve writing more C code to load previous results from the output files, which we didn't feel like doing.

The Python script `dogefood.py` does this and also makes use of some optimizations. Since Python sets use hashes, testing set membership is `O(1)`, as opposed to binary search which is `O(log n)`. Thus, we used sets to replace the binary search. Another optimization that was done was to break each even string into half, then grab even characters from each left and right string. If these even characters were not found in the even string halves, then they could not possibly be part of a valid password and were thrown out. This reduced our search space drastically - from 250k left strings to 316 and from 500k right strings to 250k, or a 2000x speedup for 1 additional second of computing time. After that, it was a matter of testing left + right combinations as before, giving us 47k possible answers.

##Doge's Password
These answers do not actually work directly. To get the actual final puzzle answer, one needs to perform a GET request to `0xd09e5ec.dogemit.party/secret/` with one of the passwords appended. This answer ends up being `amaze algorithm`.