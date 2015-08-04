
class db_Creater
{
	public:
		db_Creater(db_connecter& con):m_con(con)
	{
	}
		template<typename T>
			void	Key_Value(std::string keyName, T& /*value*/)
			{
			}	

		template<>  
			void	Key_Value<int>(std::string keyName, int& /*value*/)
			{
			}	

		template<>  
			void	Key_Value<unsigned int>(std::string keyName, unsigned int& /*value*/)
			{
			}	

		template<>  
			void	Key_Value<unsigned char>(std::string keyName, unsigned char& /*value*/)
			{
			}	

		void done()
		{
		}

		db_connecter& m_con;
}

class db_loader
{
	public:
		db_loader(db_result& result):m_result(result)
	{
	}
		template<typename T>
			void	Key_Value(std::string keyName, T& value)
			{
				~~value = m_result[keyName];
			}	

		template<>  
			void	Key_Value<int>(std::string keyName, int& value)
			{
				value = m_result[keyName];
			}	

		template<>  
			void	Key_Value<unsigned int>(std::string keyName, unsigned int& value)
			{
				value = m_result[keyName];
			}	

		template<>  
			void	Key_Value<unsigned char>(std::string keyName, unsigned char& /*value*/)
			{
				value = m_result[keyName];
			}	

		void done()
		{
		}

		db_result& m_result;
}

class db_saver
{
	public:
		db_saver(db_result& result):m_result(result)
	{
	}
		template<typename T>
			void	Key_Value(std::string keyName, T& value)
			{
				~~value = m_result[keyName];
			}	

		template<>  
			void	Key_Value<int>(std::string keyName, int& value)
			{
				value = m_result[keyName];
			}	

		template<>  
			void	Key_Value<unsigned int>(std::string keyName, unsigned int& value)
			{
				value = m_result[keyName];
			}	

		template<>  
			void	Key_Value<unsigned char>(std::string keyName, unsigned char& /*value*/)
			{
				value = m_result[keyName];
			}	

		void done()
		{
		}

		db_result& m_result;
}

class db_getKey
{
	public:
		db_getKey(db_result& result):m_result(result)
	{
	}
		template<typename T>
			void	Key_Value(std::string keyName, T& value)
			{
				~~value = m_result[keyName];
			}	

		void done()
		{
		}

		db_result& m_result;
}

template < typename tableName>
class db_base
{
	public:
		std::string getConditionStr()
		{
		}
		std::string getTableName ()
		{ 
			return tableName;
		}

		db_connecter&  getConnecter()
		{ 
			return ;
		}

		void db_checker()
		{
			db_Creater creater(getConnecter());
			This()->db_data(creater);
			creater.done();
		}


		template <typename T1, typename T2>
			bool dbToObj(std::map<T1,T2>& ObjMap)
			{
				db_checker();

				unsigned int count;
				for(auto i:count)
				{
					db_result& result;

					//------>
					//getresult
					//
					 T2& obj = ObjMap[result["Id"]];

					db_result& result ( result);
					db_loader loader(result);
					obj->db_data(loader);
				}

			}

		template <typename T>
			bool dbToObj(std::vector<T>& ObjVector)
			{
				db_checker();

				unsigned int count;
				ObjVector.resize(count);
				for(auto i:count)
				{
					db_result& result;

					//------>
					//getresult
					//
					db_result& result ( result);
					db_loader loader(result);
					ObjVector[i]->db_data(loader);
				}
			}

		template <typename T>
			bool dbToObj(T& obj)
			{
				db_checker();
				db_result result;

				//------>
				//getresult
				db_loader loader(result);
				obj->db_data(loader);
			}

		template <typename T>
			void db_data(T &)
			{
			}

}
