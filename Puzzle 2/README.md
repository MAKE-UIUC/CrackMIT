#Puzzle 2

##Starting
Hitting the Puzzle 2 link took us to a page containing a low-poly image of Doge with the text:

>pls bring doge to real world

![Screen](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%202/init.png)

There was nothing more, so we did the first thing we've come to expect to do – we viewed the page source.

##39 Images

On viewing the page source, we saw that there were 39 images that should be displayed on the page. However none of these were currently being rendered.

```
<img id='i1' class="not-needed" src="/assets/1.png" />
<img id='i2' class="not-needed" src="/assets/2.png" />
...
...
<img id='i38' class="not-needed" src="/assets/38.png" />
<img id='i39' class="not-needed" src="/assets/39.png" />
```

Clearly there were being intentionally hidden, given the class name `not-needed`. For us, this was a clear sign that we were on the right track.

Had we tried to open each image sequentially, and we would have quickly realized that a lot of these images don't actually exist. Moreover, sequentially opening 39 images is boring. So instead, we simply changed the properties of the `not-needed` class, by unchecking `display:none` in the element inspector.

This brought up 3 images. We later realized that one of the images was a duplicate. There were really only 2 unique images here.

![Screen](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%202/prints.png)


##Doge to Real World

These three images were standard letter page sized, and the text on the page that read `pls bring doge to real world`. This strongly suggested printing these images. At the time, we downloaded the images and printed them. We later realized that there was a shorter way to do all this.

####Short Cut

The page has a styling class labeled `@media print`. This is different than the standard `@media screen`. The difference is that `@media screen` is the styling used when the page is rendered on a screen. It is not used for printing; `@media print` is used for printing. 

This meant that simply hitting `⌘P` would print the 2 unique images in the manner that they *should* be printed. 

So really, all that was required before moving to the next step was - hit `⌘P`.

I suppose this should have been obvious given the text....

##Doge in the Real World

This is the part that really held us up for a while. Now that we have these two printed images, what do we do with them? There was a bunch of numbers and a bunch of lines.

We eventually realized that folded in the right way, some of the lines started to form letters. We got to this in two ways

first ripping the paper and forming the letters as seemed appropriate.
![Screen](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%202/rip.png)


Second, folding the paper like decent human beings.
![Screen](https://raw.githubusercontent.com/MAKE-UIUC/CrackMIT/master/Puzzle%202/fold.png)

##VERY WOW
Awesome! Our second answer!

Now to the next puzzle and yet another cup of gourmet coffee.

[Puzzle 2](https://github.com/MAKE-UIUC/CrackMIT/tree/master/Puzzle%203)
