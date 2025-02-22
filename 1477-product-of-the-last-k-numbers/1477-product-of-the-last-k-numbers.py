class ProductOfNumbers:

    def __init__(self):
        self.l = []
        self.p = 1

    def add(self, num: int) -> None:
        if num == 0:
            self.l = []
            self.p = 1
        else :
            self.p = self.p * num
            self.l.append(self.p)

    def getProduct(self, k: int) -> int:
        if  len(self.l) < k:
            return 0
        elif k == len(self.l):
            return self.l[-1]
        else: return self.l[-1] // self.l[-k -1]
