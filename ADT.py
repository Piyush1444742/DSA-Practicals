class SetADT:
    def __init__(self):
        self.elements = set()

    def add(self, element):
        self.elements.add(element)

    def remove(self, element):
        self.elements.discard(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)

    def intersection(self, other_set):
        return self.elements.intersection(other_set.elements)

    def union(self, other_set):
        return self.elements.union(other_set.elements)

    def difference(self, other_set):
        return self.elements.difference(other_set.elements)

    def subset(self, other_set):
        return self.elements.issubset(other_set.elements)

def main():
    set1 = SetADT()
    set2 = SetADT()

    while True:
        print("\nSet Operations Menu:")
        print("1. Add element to Set 1")
        print("2. Add element to Set 2")
        print("3. Remove element from Set 1")
        print("4. Remove element from Set 2")
        print("5. Check if element is in Set 1")
        print("6. Check if element is in Set 2")
        print("7. Get size of Set 1")
        print("8. Get size of Set 2")
        print("9. Get intersection of Set 1 and Set 2")
        print("10. Get union of Set 1 and Set 2")
        print("11. Get difference of Set 1 and Set 2")
        print("12. Check if Set 1 is subset of Set 2")
        print("13. Exit")
        
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            element = int(input("Enter element to add to Set 1: "))
            set1.add(element)
            print("Set 1:", set1.elements)
        elif choice == 2:
            element = int(input("Enter element to add to Set 2: "))
            set2.add(element)
            print("Set 2:", set2.elements)
        elif choice == 3:
            element = int(input("Enter element to remove from Set 1: "))
            set1.remove(element)
            print("Set 1:", set1.elements)
        elif choice == 4:
            element = int(input("Enter element to remove from Set 2: "))
            set2.remove(element)
            print("Set 2:", set2.elements)
        elif choice == 5:
            element = int(input("Enter element to check in Set 1: "))
            print(element, "is in Set 1" if set1.contains(element) else "is not in Set 1")
        elif choice == 6:
            element = int(input("Enter element to check in Set 2: "))
            print(element, "is in Set 2" if set2.contains(element) else "is not in Set 2")
        elif choice == 7:
            print("Size of Set 1:", set1.size())
        elif choice == 8:
            print("Size of Set 2:", set2.size())
        elif choice == 9:
            print("Intersection of Set 1 and Set 2:", set1.intersection(set2))
        elif choice == 10:
            print("Union of Set 1 and Set 2:", set1.union(set2))
        elif choice == 11:
            print("Difference of Set 1 and Set 2:", set1.difference(set2))
        elif choice == 12:
            print("Set 1 is subset of Set 2" if set1.subset(set2) else "Set 1 is not subset of Set 2")
        elif choice == 13:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
