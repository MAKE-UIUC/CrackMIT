#Puzzle 4

##Starting
Hitting the link for Puzzle 4 gave us an interactive page where clicking the dog's nose would play a couple of sound files.

`song.wav` had an interesting computerized sound to it, so of course it's time to analyze it.

#Analyzing the sound
We noticed that there was a bark at the beginning of `song.wav`. Luckily, `bark.wav` was also provided, so we opened both files in Audacity and subtracted `bark.wav` from `song.wav`, giving us [`tones.wav`](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%204/tones.wav). (We later found out that this was not actually necessary; the bark sound does not interfere with the encoding for the rest of the image.)

Now we had a sound file with what appeared to be a 400Hz tone, but we didn't know anything more than that.

##Guessing encoding formats
It's actually not all that uncommon for puzzles to encode data into sound files (aka steganography). Valve did something similar with their Portal ARG leading up to Portal 2's announcement, where images were encoded into sound files using the SSTV (slow-scan TV) encoding method - these sound files would be played back in-game when radios were moved to specific locations in levels.

Unfortunately, SSTV needs anywhere from 8 seconds to several minutes to transmit an image frame, whereas `tones.wav` is only about 2.5 seconds long.

Another thought we had was just counting whether each visible tonal spike was up or down from Audacity's center line, but doing this would be cumbersome and the audio didn't look like it was encoded in this way.

Other thoughts for encoding schemes that turned out to be incorrect: Morse Code (too slow relative to the wav file), TTY/TDD (too old of a technology to reliably find software to automate this), DTMF tones (doesn't really sound like telephone/modem sounds).

##Googling to the rescue
Turns out, if you Google "[hiding images in audio](https://www.google.com/webhp?sourceid=chrome-instant&ion=1&espv=2&es_th=1&ie=UTF-8#q=hiding%20images%20in%20audio&es_th=1)", the first result from [Lifehacker](http://lifehacker.com/5807289/how-to-hide-secret-messages-and-codes-in-audio-files) explains just how to do that and to decode the image.

Installing Sonic Visualizer and grabbing the spectrogram of the audio reveals this:

![Spectrogram](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%204/spectrogram.png)

Well, that's pretty obvious. The answer is `such hertz`.

[Puzzle 5](https://github.com/MAKE-UIUC/CrackMIT/tree/master/Puzzle%205)