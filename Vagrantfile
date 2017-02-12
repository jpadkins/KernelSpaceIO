Vagrant.configure(2) do |config|
	config.vm.box = "ubuntu/trusty64"
	config.vm.network :forwarded_port, guest: 80, host: 9000
	config.vm.synced_folder "shared", "/home/vagrant/shared"
	config.vm.provider "virtualbox" do |vb|
		vb.name = "OS_Project"
	end
end
