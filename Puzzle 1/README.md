#Puzzle 1

##Starting
Hitting the link the Puzzle 1 link took us to a page that asked us for an email address. This email address was for a Slack team for the Puzzle. The team was called _dogemit_ and had a bot named _dogebot_. _dogebot_ was fairly responsive on #General and repeatedly asked for members to message him directly, so we did.

##Messaging _dogebot_
Interacting with dogebot seemed to have a couple of rules – this is what messaging `help` resulted in.
```
dogebot speak - How to speak with doges
dogebot adapter - Reply with the adapter
dogebot echo <text> - Reply back with <text>
dogebot help - Displays all of the help commands that dogebot knows about.
dogebot help <query> - Displays all help commands that match <query>.
dogebot ping - Reply with pong
dogebot the rules - Make sure dogebot still knows the rules.
dogebot time - Reply with current time
```
Given this list, we did the next most logical thing – we messaged `speak` to dogebot. To this, he replied `so very much such pls many wow amaze`. Even right now we’re not quite sure what this is supposed to mean. But we did realize that messaging one of these words to dogebot got him to reply with some more arcane nonsense.

##Arcane Nonsense
Initially, it seemed like dogebot was spouting off random / arbitrary doge phrases. It was clear that this was going to be a long night.

After speaking to him for sometime, we realized that he was saying the same thing over and over again. He was saying
```
so very much such pls many wow amaze
very amaze is 'amaze '
very believe is 'robot'
such bark much woof
very excite is amaze + woof
wow excite
very hack is plz bark with believe
console dose loge with hack
shh this is message from dogebot
shh pls send dogebot to hackmit
```
Remember what we said about long nights?

##Javascripty?
That word is key to solving Puzzle 1. If you noticed that spoken out, dogebot’s message sounds like JavaScript – it sounds JavaScripty… Hold on – doge and JavaScript? Was this DogeScript?

It took us over an hour to figure this out. How could we have not seen this earlier? Perhaps it’s what we said about the length of the night.

A quick look over the DogeScript website made it clear that that dogebot’s message translated to the following JavaScript code.
```
var very = require('very');
var amaze = 'amaze ';
var believe = 'robot';
function bark(woof) {
    var excite = amaze + woof;
    return excite;
}
var hack = bark(believe);
console.log(hack);
// this is message from dogebot 
// pls send dogebot to hackmit
```

##Amaze Robot
It’s now obvious that we’re looking for the output of this JavaScript code. To entertain the obvious, the output of this code is `amaze robot`. Here’s our first answer!

Now to the puzzle and the next cup of gourmet coffee.

[Puzzle 2](https://github.com/MAKE-UIUC/CrackMIT/tree/master/Puzzle%202)
