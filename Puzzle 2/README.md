#Puzzle 2

##Starting
Hitting the Puzzle 2 link took us to a page with a low-poly image of Doge with the text:

>pls bring doge to real world

There nothing much more, so we did the first thing we've come to expect to do - view the page source.

##39 Images

On viewing the page source, we see that there are 39 images that should be displayed on the page. However none of these are currently being rendered

```
<img id='i1' class="not-needed" src="/assets/1.png" />
<img id='i2' class="not-needed" src="/assets/2.png" />
...
...
<img id='i38' class="not-needed" src="/assets/38.png" />
<img id='i39' class="not-needed" src="/assets/39.png" />
```

Clearly there are being intentionally hidden, given the class name `not-needed`. Seems like we're on the right track.

Now we could try to open each image sequentially, and doing that clearly shows that a lot of these images don't actually exist. Moreover, sequentially opening 39 images is boring. So instead, we simply changed the properties of the `not-needed` class, by unchecking `display:none` in the element inspector.

This brought up 3 images. We later realized that one of the images was a duplicate. There were really only 2 unique images here.

##Doge to Real World

These three images were standard letter page sized, and the text on the page that read `pls bring doge to real world`. This strongly suggested printing these images. At the time, we downloaded the images and printed them. We later realized that there was a shorter way to do all this.

####Short Cut

The page has a styling class labeled `@media print`. This is different than the standard `@media screen`. The difference is that `@media screen` is the styling used when the page is rendered on a screen. It is not used for printing; `@media print` is used for printing. 

This meant that simply hitting `⌘P` would print the 2 unique images in the manner that they *should* be printed. 

So really, all that was required before moving to the next step was - hit `⌘P`.

I suppose this should have been obvious given the text....

##Doge in the Real World

This is the part that really held us up for a while. Now that we have these two printed images, what do we do with them? There a bunch of number and a bunch of lines.