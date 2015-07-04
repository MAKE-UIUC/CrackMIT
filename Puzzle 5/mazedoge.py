__author__ = 'ericahn3'
import requests
from bs4 import BeautifulSoup
from Queue import Queue

def go_to_pos(m, p):
    if m[-1] == 'U':
        return p[0], p[1]+1
    if m[-1] == 'D':
        return p[0], p[1]-1
    if m[-1] == 'R':
        return p[0]+1, p[1]
    return p[0]-1, p[1]

BASE_URL = 'http://0xd09eeffec7.dogemit.party'
maze = set()

next_moves = Queue()
next_moves.put(('/U', (0,1)))
while not next_moves.empty():
    move = next_moves.get()
    if move[1] in maze:
        continue
    maze.add(move[1])
    r = requests.get(BASE_URL + move[0])
    soup = BeautifulSoup(r.text)
    valid = map(lambda x: x.parent['href'], soup.select('.green'))
    for i in valid:
        next_moves.put((i, go_to_pos(i, move[1])))
    sp = soup.select('.special')
    if len(sp) > 0:
        print 'Found image {} at {} - {}'.format(sp[0].text, move, sp[0]['href'])