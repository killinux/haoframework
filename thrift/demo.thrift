struct UserProfile {
  1:i32 id, // 注意这里是逗号，而不是分号
  2:string name,
  3:string blurb
} // 这里没有分号

service UserStorage{
  void store(1: UserProfile user), // 注意这里是逗号，而不是分号
  UserProfile getUser(1: i32 uid)
}
