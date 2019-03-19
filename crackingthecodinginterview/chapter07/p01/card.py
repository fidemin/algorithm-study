
from enum import Enum
import random
import time

random.seed(time.time())

class Suit(Enum):
    diamonds = 1
    clubs = 2
    hearts = 3
    spades = 4


class Card(object):
    def __init__(self, suit, number):
        self._suit = suit
        self._number = number

    def __repr__(self):
        return "%s(suit=%s,number=%d)" % (self.__class__.__name__, self._suit, self._number)


class Deck(object):
    def __init__(self):
        self.reset()

    def deal(self):
        card = self._cards.pop()
        self._used_cards.append(card)
        return card

    def reset(self):
        self._set_cards()
        self._suffle()
        self._used_cards = []

    def _set_cards(self):
        self._cards = []
        for number in range(1, 14):
            for suit in Suit:
                self._cards.append(Card(suit, number))

    def _suffle(self):
        random.shuffle(self._cards)
