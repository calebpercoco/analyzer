import time


def get_data() -> tuple:
    string_data_set = ["."] * (26 ** 5)

    temp_set = [".", ".", ".", ".", "."]

    alphabet = "abcdefghijklmnopqrstuvwxyz"

    index = 0

    for i in range(len(alphabet)):

        temp_set[4] = alphabet[i]

        for j in range(len(alphabet)):

            temp_set[3] = alphabet[j]

            for k in range(len(alphabet)):

                temp_set[2] = alphabet[k]

                for l in range(len(alphabet)):

                    temp_set[1] = alphabet[l]

                    for m in range(len(alphabet)):
                        temp_set[0] = alphabet[m]

                        string_data_set[index] = (temp_set[0] + temp_set[1] + temp_set[2] + temp_set[3] + temp_set[4])

                        index += 1

    string_data_set.sort()

    string_data_tuple = tuple(string_data_set)

    return string_data_tuple


def linear_search(container: tuple[str], element: str) -> int:
    time_start = time.time()

    for ind, x in enumerate(container):

        if x == element:
            print(f"Linear Search: {time.time() - time_start}")

            return ind

    print(f"Linear Search: {time.time() - time_start}")

    return -1


def binary_search(container: tuple[str], element: str) -> int:
    time_start = time.time()

    min_ind, max_ind = 0, len(container) - 1

    while min_ind != max_ind:

        mid_ind = (min_ind + max_ind) // 2

        mid_elem = container[mid_ind]

        if mid_elem < element:

            min_ind = mid_ind + 1

        elif mid_elem > element:

            max_ind = mid_ind - 1

        else:

            min_ind = max_ind = mid_ind

    print(f"Binary Search: {time.time() - time_start}")

    return min_ind if container[min_ind] == element else -1


def main():
    print("Generating container...")

    string_data = get_data()

    print()

    search_words = ["not_here", "mzzzz", "aaaaa"]

    for word in search_words:
        print(f"Search for... '{word}'")

        print(f"Index = {linear_search(string_data, word)}")

        print(f"Index = {binary_search(string_data, word)}")

        print()


if __name__ == '__main__':
    main()