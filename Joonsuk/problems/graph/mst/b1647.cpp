// 일단 mst를 구한 뒤 제일 긴 선을 끊는 것이 답으로 보인다.
// 하지만 정말 답일까?

// 일단 연결선 1개를 끊는 경우를 생각해보자. (2가지 그룹으로 나눌때는 트리를 어떻게 쪼개든 상관 없으므로..)
// 각각의 그룹은 서로 연결되어있고, 이 연결은 항상 최소이다. (mst이므로)
// 따라서 연결선 1개를 끊어서 그룹을 나누는 경우 들 중에서는 mst에서 제일 긴 선을 끊는것이 최소가 맞다.

// 그렇다면 1개가 아닌 여러개의 연결선을 mst에서 끊어서, 그룹을 만드는 경우에는 어떻게 될 것인가?
// 여러개를 끊는 후, 새롭게 연결선을 추가하는 것이 더 최소가 될 수는 없을까?
// 답은 아니오이다. 왜냐하면 연결선 3개를 끊는다면, 새로운 연결선 2개가 필연적으로 필요하며, 이 연결선은
// 3개의 연결선 보다 항상 큰 비용을 가지기 때문이다.
// 따라서 1개를 끊을때보다 더 적은 비용의 이득이 발생하므로, 여러개를 끊을때 보다 1개를 끊을때가 항상 이득이다.

// 결론을 말하면, 1개를 끊을때가 여러개를 끊을때보다 이득이며
// 1개를 끊는 경우에는 각 그룹이 최소 비용으로 연결되어 있으므로
// mst에서 제일 비용이 큰 선을 끊는것이 항상 최소비용을 발샌시킨다.

// 이 문제의 경우 노드의 개수인 N이 매우 크므로, 시간복잡도가 N^2인 알고리즘으로는 불가능하고
// 시간복잡도가 M log M인 크루스칼 알고리즘을 이용해야 할 것이다.