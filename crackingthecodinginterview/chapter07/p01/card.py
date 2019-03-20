
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
        self._open = False

    @property
    def open(self):
        return self._open

    @open.setter
    def open(self, open_):
        self._open = open_

    def __repr__(self):
        return "%s(suit=%s,number=%d,open=%s)" % (
            self.__class__.__name__,
            self._suit,
            self._number,
            self._open)

    def __eq__(self, other):
        return (self._suit == other._suit) and (self._number == other._number)


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


class Hand(object):
    def __init__(self):
        self._cards = []

    def receive(self, card):
        self._cards.append(card)

    def show(self):
        open_cards = []
        closed_cards = []

        for card in self._cards:
            if card.open:
                open_cards.append(card)
            else:
                closed_cards.append(card)

        return open_cards, closed_cards

