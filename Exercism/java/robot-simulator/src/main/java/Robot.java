class Robot {
    private GridPosition position;
    private Orientation orientation;

    public Robot(GridPosition position, Orientation orientation) {
        this.position = position;
        this.orientation = orientation;
    }

    public GridPosition getGridPosition() {
        return this.position;
    }

    public Orientation getOrientation() {
        return orientation;
    }

    public void turnRight() {
        switch (this.orientation) {
            case NORTH:
                this.orientation = Orientation.EAST;
                break;

            case EAST:
                this.orientation = Orientation.SOUTH;
                break;

            case SOUTH:
                this.orientation = Orientation.WEST;
                break;

            case WEST:
                this.orientation = Orientation.NORTH;
                break;
        }
    }

    public void turnLeft() {
        switch (this.orientation) {
            case NORTH:
                this.orientation = Orientation.WEST;
                break;

            case EAST:
                this.orientation = Orientation.NORTH;
                break;

            case SOUTH:
                this.orientation = Orientation.EAST;
                break;

            case WEST:
                this.orientation = Orientation.SOUTH;
                break;
        }
    }

    public void advance() {
        switch (this.orientation) {
            case NORTH:
                this.position = new GridPosition(position.getX(), position.getY()+1);
                break;

            case EAST:
                this.position = new GridPosition(position.getX()+1, position.getY());
                break;

            case SOUTH:
                this.position = new GridPosition(position.getX(), position.getY()-1);
                break;

            case WEST:
                this.position = new GridPosition(position.getX()-1, position.getY());
                break;
        }
    }

    public void simulate(String commands) {
        for (char c : commands.toCharArray()) {
            switch (c) {
                case 'R':
                    turnRight();
                    break;

                case 'L':
                    turnLeft();
                    break;

                case 'A':
                    advance();
            }
        }
    }
}
