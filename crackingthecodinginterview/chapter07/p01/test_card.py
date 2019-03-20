from unittest import TestCase
import unittest

from card import Deck, Suit, Card, Hand


class DeckTests(TestCase):
    def setUp(self):
        self.deck = Deck()

    def test_set_original_cards(self):
        self.assertEqual(52, len(self.deck._cards))

    def test_deal(self):
        card = self.deck.deal()
        self.assertIsNotNone(card)
        self.assertEqual(51, len(self.deck._cards))
        self.assertEqual(1, len(self.deck._used_cards))


class HandTests(TestCase):
    def test_receive_card(self):
        card1 = Card(Suit.diamonds, 10)
        card2 = Card(Suit.clubs, 1)
        card1.open = True
        hand = Hand()
        hand.receive(card1)
        hand.receive(card2)
        self.assertEqual(2, len(hand._cards))

    def test_receive_show(self):
        card1 = Card(Suit.diamonds, 10)
        card1.open = True
        card2 = Card(Suit.clubs, 1)
        hand = Hand()
        hand.receive(card1)
        hand.receive(card2)
        open_cards, closed_cards = hand.show()
        self.assertEqual(open_cards[0], card1)
        self.assertEqual(closed_cards[0], card2)




if __name__ == "__main__":
    unittest.main()

