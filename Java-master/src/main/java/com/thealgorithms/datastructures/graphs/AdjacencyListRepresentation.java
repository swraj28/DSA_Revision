package com.thealgorithms.datastructures.graphs;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Pair<V> {
    V nbr;
    int weight;

    // Unweighted
    Pair(V nbr) {
        this(nbr, 1);
    }

    // Weighted
    Pair(V nbr, int weight) {
        this.nbr = nbr;
        this.weight = weight;
    }
}

public class AdjacencyListRepresentation<V> {

    private Map<V, ArrayList<Pair<V>>> adj;

    public AdjacencyListRepresentation() {
        adj = new HashMap<>();
    }

    public void addVertex(V v) {
        adj.putIfAbsent(v, new ArrayList<>());
    }

    public void addEdge(V u, V v) {
        addEdge(u, v, 1, false);
    }

    public void addEdge(V u, V v, int w) {
        addEdge(u, v, w, false);
    }

    public void addEdge(V u, V v, int w, boolean isDirected) {
        addVertex(u);
        addVertex(v);
        adj.get(u).add(new Pair<>(v, w));
        if (isDirected) {
            adj.get(v).add(new Pair<>(u, w));
        }
    }

    public void printAdjacencyList() {
        for (V vertex : adj.keySet()) {
            System.out.print("Vertex " + vertex + " is connected to:");
            for (Pair<V> pair : adj.get(vertex)) {
                System.out.print(" -> " + pair.nbr + " (" + pair.weight + ")");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        AdjacencyListRepresentation<Integer> graph = new AdjacencyListRepresentation<>();

        int edges = scn.nextInt();
        scn.nextLine(); // Consume the newline

        for (int i = 0; i < edges; i++) {
            Integer src = Integer.valueOf(scn.next());
            Integer dest = Integer.valueOf(scn.next());
            int weight = scn.nextInt();
            graph.addEdge(src, dest, weight, true);
        }

        graph.printAdjacencyList();
    }
}
