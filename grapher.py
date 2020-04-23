#simple script for graph visualization
#created by Jakub Dudziński
#22.04.2020

import sys
import networkx as nx
import matplotlib.pyplot as plt

def main():
  f_name = sys.argv[1]
  connection_list = []
  header_read = False
  G = nx.Graph()

  with open(f_name, 'r') as g_file:
    for line in g_file:
      words = line.split()
      if not header_read:
        header_read = True
      else:
        t_connection = tuple(words)
        connection_list.append(t_connection)

  G.add_weighted_edges_from(connection_list)
  pos = nx.shell_layout(G)
  nx.draw(G, pos, with_labels=True)
  labels = nx.get_edge_attributes(G, 'weight')
  nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
  plt.show()
  pass

if __name__ == "__main__":
  main()
