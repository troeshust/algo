import sys

from utils import read_graph, compute_components, print_components


def main():
    g, n, m = read_graph()
    components = compute_components(g)
    print_components(components)


if __name__ == "__main__":
    sys.setrecursionlimit(200000)
    main()
