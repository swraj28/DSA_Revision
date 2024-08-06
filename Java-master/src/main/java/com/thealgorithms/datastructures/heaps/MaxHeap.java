package com.thealgorithms.datastructures.heaps;

import java.util.ArrayList;
import java.util.List;

public class MaxHeap implements Heap {

    private final List<HeapElement> maxHeap;

    public MaxHeap(List<HeapElement> listElements) {
        maxHeap = new ArrayList<>();
        for (HeapElement heapElement : listElements) {
            if (heapElement != null) {
                insertElement(heapElement);
            } else {
                System.out.println("Null element. Not added to heap");
            }
        }
        if (maxHeap.isEmpty()) {
            System.out.println("No element has been added, empty heap.");
        }
    }

    public HeapElement getElement(int elementIndex) {
        if ((elementIndex <= 0) || (elementIndex > maxHeap.size())) {
            throw new IndexOutOfBoundsException("Index out of heap range");
        }
        return maxHeap.get(elementIndex - 1);
    }

    private double getElementKey(int elementIndex) {
        if ((elementIndex <= 0) || (elementIndex > maxHeap.size())) {
            throw new IndexOutOfBoundsException("Index out of heap range");
        }
        return maxHeap.get(elementIndex - 1).getKey();
    }

    private void swap(int index1, int index2) {
        HeapElement temporaryElement = maxHeap.get(index1 - 1);
        maxHeap.set(index1 - 1, maxHeap.get(index2 - 1));
        maxHeap.set(index2 - 1, temporaryElement);
    }

    private void toggleUp(int elementIndex) {
        double key = maxHeap.get(elementIndex - 1).getKey();
        while (elementIndex > 1 && getElementKey(elementIndex / 2) < key) {
            swap(elementIndex, elementIndex / 2);
            elementIndex = elementIndex / 2;
        }
    }

    private void toggleDown(int elementIndex) {
        double key = maxHeap.get(elementIndex - 1).getKey();
        while (2 * elementIndex <= maxHeap.size()) {
            int childIndex = 2 * elementIndex;
            if (childIndex < maxHeap.size() && getElementKey(childIndex + 1) > getElementKey(childIndex)) {
                childIndex++;
            }
            if (key >= getElementKey(childIndex)) {
                break;
            }
            swap(elementIndex, childIndex);
            elementIndex = childIndex;
        }
    }

    private HeapElement extractMax() {
        if (maxHeap.isEmpty()) {
            throw new IndexOutOfBoundsException("Heap is empty");
        }
        HeapElement max = maxHeap.get(0);
        deleteElement(1);  // Pass 1-based index for root element
        return max;
    }

    @Override
    public final void insertElement(HeapElement element) {
        maxHeap.add(element);
        toggleUp(maxHeap.size());
    }

    @Override
    public void deleteElement(int elementIndex) {
        if (maxHeap.isEmpty()) {
            throw new IndexOutOfBoundsException("Attempt to delete an element from an empty heap");
        }
        if ((elementIndex > maxHeap.size()) || (elementIndex <= 0)) {
            throw new IndexOutOfBoundsException("Index out of heap range");
        }
        if (elementIndex == maxHeap.size()) {
            maxHeap.remove(maxHeap.size() - 1);
        } else {
            maxHeap.set(elementIndex - 1, maxHeap.get(maxHeap.size() - 1));
            maxHeap.remove(maxHeap.size() - 1);
            if (elementIndex > 1 && getElementKey(elementIndex) > getElementKey(elementIndex / 2)) {
                toggleUp(elementIndex);
            } else {
                toggleDown(elementIndex);
            }
        }
    }

    @Override
    public HeapElement getElement() throws EmptyHeapException {
        if (maxHeap.isEmpty()) {
            throw new EmptyHeapException("Heap is empty. Error retrieving element");
        }
        return extractMax();
    }

    public static void main(String[] args) {
        // Create a list of HeapElements
        List<HeapElement> elements = new ArrayList<>();
        elements.add(new HeapElement(10.5));
        elements.add(new HeapElement(5.2));
        elements.add(new HeapElement(14.7));
        elements.add(new HeapElement(3.8));

        // Create a MaxHeap with the list of elements
        MaxHeap maxHeap = new MaxHeap(elements);

        // Display the elements in the heap
        for (int i = 1; i <= elements.size(); i++) {
            System.out.println("Element " + i + ": " + maxHeap.getElement(i).getKey());
        }

        // Extract the maximum element
        HeapElement maxElement = maxHeap.extractMax();
        System.out.println("Extracted max element: " + maxElement.getKey());

        // Display the elements in the heap after extraction
        for (int i = 1; i <= maxHeap.size(); i++) {
            System.out.println("Element " + i + ": " + maxHeap.getElement(i).getKey());
        }
    }

    // A helper method to get the current size of the heap
    public int size() {
        return maxHeap.size();
    }
}
