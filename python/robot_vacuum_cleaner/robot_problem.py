from enum import Enum

"""
Problem: A cleaning robot must clean a room. It can move in one direction, clean one cell of space at a time.
         Robot can turn left and turn right in place. When robot makes a move it returns True or False depending on
         whether it did move or something blocked it.
         Write a method clean_room() in which robot will clean the whole room.

Notes:   Robot doesn't know a map of the room, it only can use method move()
         room list represented below is there to mimic an actual room space
         in order to make method move() work correctly.
"""


room = [(0, 2), (0, 3), (1, 2), (1, 3),
        (2, 0), (2, 1), (2, 2), (2, 3), (2, 4),
        (3, 0), (3, 1), (3, 2), (3, 3), (3, 4),
        (4, 2), (4, 3)]

simple_room = [(0, 2),
               (1, 2),
               (2, 0), (2, 1), (2, 2), (2, 3), (2, 4),
               (3, 2),
               (4, 2)]

robot_position = (2, 2)


class Coordinate(object):

    def __init__(self, coordinate_tuple: tuple):
        self.first = coordinate_tuple[0]
        self.second = coordinate_tuple[1]

    def __add__(self, other):
        return Coordinate((self.first+other.first, self.second+other.second))

    def __sub__(self, other):
        return Coordinate((self.first-other.first, self.second-other.second))

    def __str__(self):
        return '{0}, {1}'.format(self.first, self.second)

    def __eq__(self, other):
        return self.first == other.first and self.second == other.second

    def to_tuple(self):
        return self.first, self.second


class Direction(Enum):

    UP = (-1, 0)
    DOWN = (1, 0)
    RIGHT = (0, 1)
    LEFT = (0, -1)

    def __init__(self, first, second):
        self.first = first
        self.second = second
        self._value_ = (self.first, self.second)

    def __add__(self, other):
        return Coordinate((self.first+other.first, self.second+other.second))


class Robot(object):
    _map = list()

    def __init__(self, starting_point, init_direction=Direction.UP):
        self.direction = init_direction
        self.current_position = starting_point if isinstance(starting_point, Coordinate) else Coordinate(starting_point)
        self.visited_cells = list()

    @classmethod
    def upload_map(cls, coordinates):
        cls._map = coordinates

    def move(self):
        # print(self.current_position)
        new_move = self.current_position + self.direction
        # print(new_move)
        possible = new_move.to_tuple() in Robot._map
        self.current_position = new_move if possible else self.current_position
        return possible

    def turn_left(self):
        left_direction = self.direction is Direction.LEFT
        up_direction = self.direction is Direction.UP
        down_direction = self.direction is Direction.DOWN
        self.direction = Direction.LEFT if up_direction or down_direction \
            else Direction.DOWN if left_direction else Direction.UP

    def turn_right(self):
        right_direction = self.direction is Direction.RIGHT
        up_direction = self.direction is Direction.UP
        down_direction = self.direction is Direction.DOWN
        self.direction = Direction.RIGHT if up_direction or down_direction \
            else Direction.DOWN if right_direction else Direction.UP

    def clean(self):
        self.visited_cells.append(self.current_position) if self.current_position not in self.visited_cells else None

    def add_to_stack(self, stack):
        up = self.current_position + Direction.UP
        down = self.current_position + Direction.DOWN
        left = self.current_position + Direction.LEFT
        right = self.current_position + Direction.RIGHT
        stack.append(up) if up not in self.visited_cells and up not in stack else None
        stack.append(down) if down not in self.visited_cells and down not in stack else None
        stack.append(left) if left not in self.visited_cells and left not in stack else None
        stack.append(right) if right not in self.visited_cells and right not in stack else None

    def clean_room(self):
        stack = list()
        self.add_to_stack(stack)

        while stack:
            self.clean()
            cur = stack.pop()
            delta = cur - self.current_position
            self.direction = delta

            if self.move():
                self.add_to_stack(stack)  # TODO: optimize adding to stack (check for not possible moves)


def assert_coordinates(map_tuples, coordinates):
    for coordinate in coordinates:
        if coordinate.to_tuple() not in map_tuples:
            return False
    return True


if __name__ == "__main__":
    robot = Robot(robot_position)
    # robot.upload_map(room)
    robot.upload_map(room)
    robot.clean_room()
    print(assert_coordinates(room, robot.visited_cells))
