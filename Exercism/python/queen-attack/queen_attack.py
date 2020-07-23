class Queen:
    def __init__(self, row, column):
        if row < 0 or column < 0 or row > 7 or column > 7:
            raise ValueError("Invalid position")

        self.row = row
        self.column = column

    def can_attack(self, other):
        if self.row == other.row and self.column == other.column:
            raise ValueError("Queens can't have the same position")

        return self.row == other.row or self.column == other.column \
            or abs(self.row - other.row) == abs(self.column - other.column)