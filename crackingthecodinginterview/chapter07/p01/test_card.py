from unittest import TestCase
import unittest

from card import Deck


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



if __name__ == "__main__":
    unittest.main()

